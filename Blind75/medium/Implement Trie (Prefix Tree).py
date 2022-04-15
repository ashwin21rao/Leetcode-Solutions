class Trie:

    def __init__(self):
        self.children = {}  # character -> child Trie node
        self.endOfWord = False

    def insert(self, word: str) -> None:
        node = self
        
        for ch in word:
            if ch not in node.children:
                node.children[ch] = Trie()
            node = node.children[ch]
        
        node.endOfWord = True

    def search(self, word: str) -> bool:
        node = self
        
        for ch in word:
            if ch not in node.children:
                return False
            node = node.children[ch]
        
        return node.endOfWord

    def startsWith(self, prefix: str) -> bool:
        node = self
        
        for ch in prefix:
            if ch not in node.children:
                return False
            node = node.children[ch]
        
        return True

"""
Each trie node has:
    - bool endOfWord: True if a word ends at this node
    - children: unordered map of characters to corresponding children nodes

time complexity: O(L) for each operation
"""