class MyHashSet {
public:
    int buckets = 1000;  // number of buckets
    vector<list<int>> hash;  // each bucket has a linked list
    
    MyHashSet() : hash(1000) {
        
    }
    
    int findHash(int key) {
        return key % buckets;
    }
    
    void add(int key) {
        int val = findHash(key);
        
        // add key if not already present
        if (!contains(key))
            hash[val].push_back(key);
    }
    
    void remove(int key) {
        int val = findHash(key);
        
        hash[val].remove(key);
    }
    
    bool contains(int key) {
        int val = findHash(key);
        
        return find(hash[val].begin(), hash[val].end(), key) != hash[val].end();
    }
};

/*
- our hashmap consists of 1000 buckets.
- each bucket consists of a linked list of keys.
- the hash function maps each key to a bucket.
  here, we use the hash (key % num_buckets).

let k = number of buckets
time complexity:
    - add: O(n / k)
    - remove: O(n / k)
    - contains: O(n / k)

optimization: 
    - using a balanced BST (c++ set) in place of a linked 
      list will make all time complexities O(log (n / k)).
*/