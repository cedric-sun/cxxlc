// cesun, 9/5/20 3:18 PM.

#include <unordered_map>
#include <list>

class LRUCache {
public:
    using IntPairList = std::list<std::pair<int, int>>;

    std::unordered_map<int, IntPairList::const_iterator> k2ent;
    IntPairList kvList;
    const int cap;

    LRUCache(int capacity) : cap(capacity) {
        k2ent.reserve(capacity);
    }

    void touch(int key, int val) {
        kvList.emplace_front(key, val);
        k2ent[key] = kvList.cbegin();
    }

    int get(int key) {
        auto it = k2ent.find(key);
        if (it == k2ent.cend())
            return -1;
        int val = it->second->second;
        kvList.erase(it->second);
        touch(key, val);
        return val;
    }


    // critical: check if is an overwrite even if cap is not reach
    void put(int key, int value) {
        auto it = k2ent.find(key);
        if (it != k2ent.cend()) { // if is an overwrite, do it anyway
            kvList.erase(it->second);
            k2ent.erase(it);
        } else if (k2ent.size() >= cap) { // set space for new entry
            k2ent.erase(kvList.back().first);
            kvList.pop_back();
        }
        touch(key, value);
    }
};

#include <cstdio>

int main() {
    LRUCache x{10};
    x.put(10, 13);
    x.put(3, 17);
    x.put(6, 11);
    x.put(10, 5);
    x.put(9, 10);
    printf("%d\n", x.get(13));
    x.put(2, 19);
    printf("%d\n", x.get(2));
    printf("%d\n", x.get(3));
    x.put(5, 25);
    printf("%d\n", x.get(8));
    x.put(9, 22);
    x.put(5, 5);
    x.put(1, 30);
    printf("%d\n", x.get(11));
    x.put(9, 12);
    printf("%d\n", x.get(7));
    printf("%d\n", x.get(5));
    printf("%d\n", x.get(8));
    printf("%d\n", x.get(9));
    x.put(4, 30);
    x.put(9, 3);
    printf("%d\n", x.get(9));
    printf("%d\n", x.get(10));
    printf("%d\n", x.get(10));
    x.put(6, 14);
    x.put(3, 1);
    printf("%d\n", x.get(3));
    x.put(10, 11);
    printf("%d\n", x.get(8));
    x.put(2, 14);
    printf("%d\n", x.get(1));
    printf("%d\n", x.get(5));
    printf("%d\n", x.get(4));
    x.put(11, 4);
    x.put(12, 24);
    x.put(5, 18);
    printf("%d\n", x.get(13));
    x.put(7, 23);
    printf("%d\n", x.get(8));
    printf("%d\n", x.get(12));
    x.put(3, 27);
    x.put(2, 12);
    printf("%d\n", x.get(5));
    x.put(2, 9);
    x.put(13, 4);
    x.put(8, 18);
    x.put(1, 7);
    printf("%d\n", x.get(6));
    x.put(9, 29);
    x.put(8, 21);
    printf("%d\n", x.get(5));
    x.put(6, 30);
    x.put(1, 12);
    printf("%d\n", x.get(10));
    x.put(4, 15);
    x.put(7, 22);
    x.put(11, 26);
    x.put(8, 17);
    x.put(9, 29);
    printf("%d\n", x.get(5));
    x.put(3, 4);
    x.put(11, 30);
    printf("-------------WTF: %d----------------\n", x.kvList.size());
    printf("%d\n", x.get(12));
    x.put(4, 29);
    printf("%d\n", x.get(3));
    printf("%d\n", x.get(9));
    printf("%d\n", x.get(6));
    x.put(3, 4);
    printf("%d\n", x.get(1));
    printf("%d\n", x.get(10));
    x.put(3, 29);
    x.put(10, 28);
    x.put(1, 20);
    x.put(11, 13);
    printf("%d\n", x.get(3));
    x.put(3, 12);
    x.put(3, 8);
    x.put(10, 9);
    x.put(3, 26);
    printf("%d\n", x.get(8));
    printf("%d\n", x.get(7));
    printf("%d\n", x.get(5));
    x.put(13, 17);
    x.put(2, 27);
    x.put(11, 15);
    printf("%d\n", x.get(12));
    x.put(9, 19);
    x.put(2, 15);
    x.put(3, 16);
    printf("%d\n", x.get(1));
    x.put(12, 17);
    x.put(9, 1);
    x.put(6, 19);
    printf("%d\n", x.get(4));
    printf("%d\n", x.get(5));
    printf("%d\n", x.get(5));
    x.put(8, 1);
    x.put(11, 7);
    x.put(5, 2);
    x.put(9, 28);
    printf("%d\n", x.get(1));
    x.put(2, 2);
    x.put(7, 4);
    x.put(4, 22);
    x.put(7, 24);
    x.put(9, 26);
    x.put(13, 28);
    x.put(11, 26);
}
