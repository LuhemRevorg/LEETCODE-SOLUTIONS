class LRUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.storage = {}
        self.queue = []
        self.count = 0

    def get(self, key: int) -> int:
        val = self.storage.get(key)
        if val is not None:
            self.queue.remove(key)
            self.queue.append(key)
            return val
        return -1

    def put(self, key: int, value: int) -> None:

        if self.storage.get(key) is not None:
            self.storage[key] = value
            self.queue.remove(key)
            self.queue.append(key)
            return

        if self.count < self.capacity:
            self.count += 1
            self.storage[key] = value
            self.queue.append(key)
        else:
            least_used = self.queue.pop(0)
            del self.storage[least_used]
            self.storage[key] = value
            self.queue.append(key)

            
        


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
