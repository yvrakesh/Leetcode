class LRUCache {
    #include<bits/stdc++.h>
    int capacity;
    list <int> keys;
    unordered_map <int, pair<int,list <int> :: iterator>> cache;
public:
    LRUCache(int _capacity) {
        capacity = _capacity;
    }
    
    // Search for the key in the cache
    int get(int key) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        // If element is existing in the map
        if(cache.find(key) != cache.end()){
            // Erase the element from linked list -> O(1) 
            // Since we know the address of the node from the map
            keys.erase(cache[key].second);
            // Insert key to the front of the linked list -> O(1)
            keys.push_front(key);
            // Change the address of node in the map -> O(1)
            cache[key].second = keys.begin();
            // Return it's value from the map -> O(1)
            return cache[key].first;
        }
        // If element is not found in the map
        return -1;
    }
    
    // Insert the key into cache
    void put(int key, int value) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        // If element already in cache then change the value with new "value"
        if(cache.find(key) != cache.end()){
            // Erase key from the linked list -> O(1)
            keys.erase(cache[key].second);
            // Insert it to the front of the linked list -> O(1)
            keys.push_front(key);
            // Change the map value with new one and it's address
            cache[key] = {value,keys.begin()};
        }
        // If element doesn't exist
        else{
            // Check if it's capacity is full
            if(keys.size() == capacity){
                // Erase Least Recently used node from the map(Last node in list)
                cache.erase(keys.back());
                // Erase LRU node from linkedlist
                keys.pop_back();
            }
            // Insert key to the front of the list
            keys.push_front(key);
            // Update Map with new key, value
            cache[key] = {value,keys.begin()};
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */