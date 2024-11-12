// Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.
// Implement the LRUCache class:
// LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
// int get(int key) Return the value of the key if the key exists, otherwise return -1.
// void put(int key, int value) Update the value of the key if the key exists. Otherwise,
// add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation,
// evict the least recently used key.
// The functions get and put must each run in O(1) average time complexity.

#include <unordered_map>
using namespace std;

class Node
{
public:
    Node();
    Node(const Node& node);
    friend std::ostream operator<<(const std::ostream& os, Node& node);
    friend std::istream operator>>(const std::istream& is, Node& node);
    int K, V;
    Node *N;
    Node *P;
    Node(int k, int v) : K(k), V(v),
                         N(nullptr), P(nullptr) {}
};

class LRUCache
{
public:
    LRUCache();
    LRUCache(const LRUCache& cache);
    LRUCache(const LRUCache&& cache);
    friend std::ostream operator<<(const std::ostream&, LRUCache& cache);
    LRUCache(int capacity)
    {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->N = tail;
        tail->P = head;
    }

    int get(int key)
    {
        if(cache.find(key) != cache.end()){
            Node* node = cache[key];
            move_front(node);
            return node->V;
        }   
        return -1;
    }

    void put(int key, int value)
    {
        if(cache.find(key) != cache.end())
        {
            Node* EN = cache[key];
            EN->K = value;
            move_front(EN);
        } else {
            if(cache.size() == capacity)
            {
                Node* least_used = tail->P;
                remove_node(least_used);
                cache.erase(least_used->K);
                delete(least_used);
            }

            Node* most_active = new Node(key, value);
            cache[key] = most_active;
            insert_front(most_active);
        }
    }
private:
    unordered_map<int, Node *> cache;
    int capacity;
    Node *head;
    Node *tail;

    void remove_node(Node* node)
    {
        Node* PNode = node->P;
        Node* NNode = node->N;
        PNode->N = NNode;
        NNode->P = PNode;
    }

    void insert_front(Node* node) 
    {
        node->N = head->N;
        node->P = head;
        head->N->P = node;
        head->N = node;
    }

    void move_front(Node* node)
    {
        remove_node(node);
        insert_front(node);
    }

};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */