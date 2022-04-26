class MyHashMap {
public:
    int buckets = 1000;
    vector<list<pair<int, int>>> hash;
    
    MyHashMap() : hash(1000) {
        
    }
    
    int findHash(int key) {
        return key % buckets;
    }
    
    void put(int key, int value) {
        int val = findHash(key);
        auto it = search(key);
        
        // key found
        if (it != hash[val].end())
            it->second = value;
        else
            hash[val].push_back({key, value});
    }
    
    int get(int key) {
        int val = findHash(key);
        auto it = search(key);
        
        // key found
        if (it != hash[val].end())
            return it->second;
        
        return -1;
    }
    
    void remove(int key) {
        int val = findHash(key);
        auto it = search(key);
        
        // key found
        if (it != hash[val].end())
            hash[val].erase(it);
    }
    
    list<pair<int, int>>::iterator search(int key) {
        int val = findHash(key);
        
        // search for key in bucket
        for (auto it=hash[val].begin(); it != hash[val].end(); it++) {
            if (it->first == key)
                return it;
        }
        
        // key not found
        return hash[val].end();
    }
};

/*
- our hashmap consists of 1000 buckets.
- each bucket consists of a linked list of key-value pairs.
- the hash function maps each key to a bucket.
  here, we use the hash (key % num_buckets).

let k = number of buckets
time complexity:
    - add: O(n / k)
    - remove: O(n / k)
    - contains: O(n / k)

optimization: 
    - using a balanced BST (c++ map) in place of a linked 
      list will make all time complexities O(log (n / k)).
*/