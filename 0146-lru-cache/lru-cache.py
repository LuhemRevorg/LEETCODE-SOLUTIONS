class LRUCache:

    class Node:
        def __init__(self, key, val, prev=None, next=None):
            self.key = key
            self.val = val
            self.prev = prev
            self.next = next

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.map = {}
        self.front = self.Node(float('inf'), 0)
        self.back = self.Node(float('-inf'), 0)
        self.front.next = self.back
        self.back.prev = self.front

    def __update(self, node):
        node.prev.next = node.next # Connect node prev with node next
        node.next.prev = node.prev # Connect node next to node.prev
        self.front.next.prev = node # front.next to node
        node.next = self.front.next # node to front.next
        node.prev = self.front
        self.front.next = node # front to node

    def get(self, key: int) -> int:
        if key in self.map:
            self.__update(self.map[key])
            return self.map[key].val
        return -1

    def put(self, key: int, value: int) -> None:

        if key in self.map:
            self.map[key].val = value
            self.__update(self.map[key])

        elif len(self.map) >= self.capacity:
            ky = self.back.prev.key
            node = self.Node(key, value, self.front, self.front.next)
            self.front.next.prev = node
            self.front.next = node
            self.map[key] = node
            del self.map[ky]
            # remove back.prev
            self.back.prev.prev.next = self.back
            old = self.back.prev
            self.back.prev = self.back.prev.prev
            del old
        else:
            node = self.Node(key, value, self.front, self.front.next)
            self.map[key] = node
            self.front.next.prev = node
            self.front.next = node
        
        
            
        


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
