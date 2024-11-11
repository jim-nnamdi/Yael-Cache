
#include <unordered_map>

enum cache_state {MOST, LEAST, NEW};
template <typename ... Ts>
bool is_any_of(cache_state s, const Ts& ... ts){
    return ((s == ts) || ...);
}

template <cache_state ... cs>
bool is_any_ofs(cache_state s) {
    return ((s == cs) || ...);
}

template <typename ... Ts>
class Qcache{
    class CNode {
        public:
        size_t key, value;
        CNode* nextCNode;
        CNode* prevCNode;
        CNode(size_t key, value) key(key), value(value), 
            nextCNode(nulltpr), prevCNode(nullptr){}
    };
    public:
    size_t capacity;
    unordered_map<size_t, CNode*> cc;
    CNode* cnode_top, cnode_bottom;
    Qcache(const Qcache& qc);
    Qcache(size_t cap);
    std::ostream operator << (std::ostream& qc, size_t k);
    Qcache(Ts ... args) {
        std::cout << ... << args;
        std::cout << sizeof ... (args);
    }
};