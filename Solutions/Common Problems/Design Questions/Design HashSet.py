class MyHashSet:

    def __init__(self):
        self.buckets = 1000
        self.hash = [[] for _ in range(self.buckets)]

    def findHash(self, key):
        return key % self.buckets
        
    def add(self, key: int) -> None:
        bucket = self.findHash(key)
        
        if not self.contains(key):
            self.hash[bucket].append(key)    

    def remove(self, key: int) -> None:
        bucket = self.findHash(key)
        
        if self.contains(key):
            self.hash[bucket].remove(key)

    def contains(self, key: int) -> bool:
        bucket = self.findHash(key)
        
        return key in self.hash[bucket]


# Your MyHashSet object will be instantiated and called as such:
# obj = MyHashSet()
# obj.add(key)
# obj.remove(key)
# param_3 = obj.contains(key)