class LRUCache {
public:
    int capacity;
    list<int> cache;
    unordered_map<int, list<int>::iterator> itMap;
    unordered_map<int, int> valueMap;
    
    void evict() {
        int key = cache.back();
        cache.pop_back();
        itMap.erase(key);
        valueMap.erase(key);
    }
    
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(valueMap.find(key) != valueMap.end()) {
            updateLRU(key);
            return valueMap[key];
        }
        return -1;
    }
    
    void updateLRU(int key) {
        if(valueMap.find(key) != valueMap.end())
            cache.erase(itMap[key]);
        cache.push_front(key);
        itMap[key] = cache.begin();
    }
    
    void put(int key, int value) {
        if(valueMap.find(key) != valueMap.end()) {
            updateLRU(key);
            valueMap[key] = value;
            return;
        }
        if(cache.size() == capacity) {
            evict();
        }
        updateLRU(key);
        valueMap[key] = value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


