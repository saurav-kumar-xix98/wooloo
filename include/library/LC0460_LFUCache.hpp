#pragma once

#include <list>
#include <unordered_map>

namespace LC0460 {
    class LFUCache {
        using InnerList = std::list<std::pair<int, int>>;
        using OuterList = std::list<std::pair<int, InnerList>>;
        using KeyIteratorPairMap = std::unordered_map<int, std::pair<OuterList::iterator, InnerList::iterator>>;
    public:
        LFUCache(int capacity);
        int get(int key);
        void put(int key, int value);
    private:
        int read(int key);
        void write(int key, int value);
        void increaseFrequency(int key);
        void evict();
        int capacity;
        int size;
        OuterList allValues;
        KeyIteratorPairMap keyIteratorPairMap;
    };
}
