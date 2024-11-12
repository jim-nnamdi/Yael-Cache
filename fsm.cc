
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

template <int N>
struct abs {
    static_assert( N != INT_MIN);
    static constexpr int value = (N < 0 ) ? -N : N;
};