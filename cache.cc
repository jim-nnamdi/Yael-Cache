#include <unordered_map>

class Node {
    public:
    int K, V;
    Node* next;
    Node* prev;

    Node(int key, int val) : K(key), V(val), next(nullptr), prev(nullptr){}
};

class LRUcache {
    private:
    std::unordered_map<int, Node*> cache;
    int capacity;
    Node* head; 
    Node* tail;

    void removeNode(Node* node) {
        Node* P = node->prev;
        Node* N = node->next;
        P->next = N; 
        N->prev = P;
    }

    void insertFront(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    void moveToFront(Node* node){
        removeNode(node);
        insertFront(node);
    }

    public:
    LRUcache(int cap): capacity(cap) {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if(cache.find(key) != cache.end()) {
            Node* node = cache[key];
            moveToFront(node);
            return node->V;
        }
        return -1;
    }

    int put(int k, int v) {
        if(cache.find(k) != cache.end()){
            Node* node = cache[k];
            node->V  =  v;
            moveToFront(node);
        } else {
            if(cache.size() == capacity){
                Node* tailP = tail->prev;
                removeNode(tailP);
                cache.erase(tailP->K);
                delete tailP;
            } 
            Node* newNode = new Node(k, v);
            cache[k] = newNode;
            insertFront(newNode);
        }
    }
};