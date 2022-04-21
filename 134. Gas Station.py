class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        start = 0
        remain = [0, 0]
        for i in range(len(gas)):
            remain[1] += (gas[i] - cost[i])
            if remain[1] < 0:
                start = i+1
                remain[0] += remain[1]
                remain[1] = 0
        if remain[0] + remain[1] < 0:
            return -1
        return start
        
