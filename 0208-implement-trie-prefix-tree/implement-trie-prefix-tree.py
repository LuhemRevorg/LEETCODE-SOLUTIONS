class Trie:
    def __init__(self):
        self.children = [None] * 26
        self.is_end = False

    def insert(self, word: str) -> None:
        node = self
        for ch in word:
            i = ord(ch) - ord('a')
            if node.children[i] is None:
                node.children[i] = Trie()
            node = node.children[i]
        node.is_end = True

    def search(self, word: str) -> bool:
        node = self._find(word)
        return node is not None and node.is_end

    def startsWith(self, prefix: str) -> bool:
        return self._find(prefix) is not None

    def _find(self, word: str):
        node = self
        for ch in word:
            i = ord(ch) - ord('a')
            if node.children[i] is None:
                return None
            node = node.children[i]
        return node


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)
