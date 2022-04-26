class MyHashMap(object):

    def __init__(self):
        self.buckets = 1000
        self.hash = [[] for _ in range(self.buckets)]
    
    def findHash(self, key):
        return key % self.buckets
    
    def put(self, key, value):
        """
        :type key: int
        :type value: int
        :rtype: None
        """
        
        bucket = self.findHash(key)
        
        for i, (k, val) in enumerate(self.hash[bucket]):
            if k == key:
                self.hash[bucket][i] = (key, value)
                return
        
        self.hash[bucket].append((key, value))

    def get(self, key):
        """
        :type key: int
        :rtype: int
        """
        
        bucket = self.findHash(key)
        
        for k, val in self.hash[bucket]:
            if key == k:
                return val
        
        return -1

    def remove(self, key):
        """
        :type key: int
        :rtype: None
        """
        
        bucket = self.findHash(key)
        
        for i, (k, val) in enumerate(self.hash[bucket]):
            if key == k:
                self.hash[bucket].pop(i)
                break


# Your MyHashMap object will be instantiated and called as such:
# obj = MyHashMap()
# obj.put(key,value)
# param_2 = obj.get(key)
# obj.remove(key)