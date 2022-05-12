class Solution:
    def isHappy(self, n: int) -> bool:
        nSet = set()
        while n != 1:
            if n in nSet:
                return False
            nSet.add(n)
            squareSum = 0
            while n:
                squareSum += (n % 10)*(n % 10)
                n //= 10
            n = squareSum
        return True
