class TimeMap:

    def __init__(self):
        self.timed = list() # timestamp, value
        self.store = {}


    def set(self, key: str, value: str, timestamp: int) -> None:
        if key in self.store:
            idx = self.store[key]
            self.timed[idx].append((timestamp, value))
        else:
            self.store[key] = len(self.timed)
            self.timed.append([(timestamp, value)])

    def get(self, key: str, timestamp: int) -> str:
        if key not in self.store:
            return ""
        idx = self.store[key]
        index = bisect_right(self.timed[idx], (timestamp + 1,))
        return self.timed[idx][index - 1][1] if index else ""

# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)
