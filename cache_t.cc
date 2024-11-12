#include <unordered_map>


template <typename B>
class Node {
    public:
    B key, val;
    Node* next;
    Node* prev;
    Node(B key, B val) : key(key), val(val), next(nullptr), prev(nullptr){}
};

template <typename A>
class LRUcache {
    private:
    unordered_map<size_t, Node*> cache;
    size_t capacity; 
    Node* head; 
    Node* tail;

    void removeNode(Node* node) {
        Node* P_Node = node->prev;
        Node* N_Node = node->next;
        P_Node->next = N_Node;
        N_Node->prev = P_Node;
    }

    void insertFront(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    void moveFront(Node* node) {
        removeNode(node);
        insertFront(node);
    }

    public:
    LRUCache();
    LRUCache(const LRUCache& cache);
    LRUCache(const LRUCache&& cache);
    friend std::ostream operator<<(const std::ostream&, LRUCache& cache);
    LRUcache(size_t cap): capacity(cap) {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    int get(size_t key) {
        if(cache.find(key) != cache.end()) {
            Node* node = cache[key];
            moveFront(node);
            return node->val;
        }
        return -1;
    }
    
    int put(size_t key, size_t val) {
        if(cache.find(key) != cache.end()) {
            Node* node = cache[key];
            node->val = val;
            moveFront(node);
        } else {
            if(cache.size() == capacity) {
                Node* lastNode =  tail->prev;
                removeNode(lastNode);
                cache.erase(lastNode->key);
                delete lastNode;
            }
            Node* newNode = new Node(key, val);
            cache[key] = newNode;
            insertFront(newNode);
        }
    }
};