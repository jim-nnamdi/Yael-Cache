# Yael Cache

This is a personalised algorithm which implements an LRU use case for Database Optimizations and Filesystems. Apparently Databases uses an LRU cache to store frequently accessed data, and on query it returns the already cached data increasing query speed thereby decreasing latency. Same intuition goes for filesystems where a system caches most accessed files thereby letting users gain access quickly to recently used files, this is used in Datacenter file engineering.

> [!TIP]  

| Operation          | Time Complexity | Explanation                                  |
|--------------------|-----------------|----------------------------------------------|
| `get_fs(key)`         | `O(1)`          | Hash map lookup + doubly linked list update  |
| `put_fs(key)`         | `O(1)`          | Hash map lookup + doubly linked list update  |
| `add_fs(key, value)`  | `O(1)`          | Hash map insertion/update + list adjustments |
| `remove_fs(key)`      | `O(1)`          | Hash map lookup + doubly linked list update  |
| **Space Complexity** | **O(C)**         | Space to store up to \( C \) items           |
