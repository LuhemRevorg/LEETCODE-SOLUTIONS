class MinStack:

    def __init__(self):
        self.arr = []
        self.m = []
        

    def push(self, val: int) -> None:
        self.arr.append(val)
        if len(self.m) == 0 or val < self.m[-1]:
            self.m.append(val)
        else:
            self.m.append(self.m[-1])
    def pop(self) -> None:
        self.arr.pop()        
        self.m.pop()
    def top(self) -> int:
        return self.arr[-1]

    def getMin(self) -> int:
        return self.m[-1]


        


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()