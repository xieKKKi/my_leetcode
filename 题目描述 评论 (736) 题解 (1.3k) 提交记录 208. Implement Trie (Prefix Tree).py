class Trie:

    def __init__(self):
        self.wordSet = set()
        self.prefixSet = set()

    def insert(self, word: str) -> None:
        self.wordSet.add(word)
        for i in range(1, len(word)+1):
            if word[:i] not in self.prefixSet:
                self.prefixSet.add(word[:i])

    def search(self, word: str) -> bool:
        if word in self.wordSet:
            return True
        else:
            return False

    def startsWith(self, prefix: str) -> bool:
        if prefix in self.prefixSet:
            return True
        else:
            return False
