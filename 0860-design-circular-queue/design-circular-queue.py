class MyCircularQueue:
    def __init__(self, k: int):
        self.q = [0] * k
        self.head = 0 
        self.size = 0
        self.cap = k

    def enQueue(self, value: int) -> bool:
        if self.size == self.cap:
            return False
        self.q[(self.head + self.size) % self.cap] = value
        self.size += 1
        return True

    def deQueue(self) -> bool:
        if self.size == 0:
            return False
        self.head = (self.head + 1) % self.cap
        self.size -= 1
        return True

    def Front(self) -> int:
        return -1 if self.size == 0 else self.q[self.head]

    def Rear(self) -> int:
        return -1 if self.size == 0 else self.q[(self.head + self.size - 1) % self.cap]

    def isEmpty(self) -> bool:
        return self.size == 0

    def isFull(self) -> bool:
        return self.size == self.cap
