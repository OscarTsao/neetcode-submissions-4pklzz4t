class TimeMap:

    def __init__(self):
        self.store = defaultdict(list)        

    def set(self, key: str, value: str, timestamp: int) -> None:
        self.store[key].append((timestamp, value))

    def get(self, key: str, timestamp: int) -> str:
        values = self.store[key]

        left = 0
        right = len(values) - 1
        res = ""

        while (left <= right):
            pivot = (left + right) // 2
            if values[pivot][0] <= timestamp:
                res = values[pivot][1]
                left = pivot + 1
            else: 
                right = pivot - 1
            
        return res
