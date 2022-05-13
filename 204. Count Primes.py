class Solution:
    def countPrimes(self, n: int) -> int:  # 埃氏筛
        isPrime = [1]*n
        count = 0
        for i in range(2, n):
            if isPrime[i]:
                count += 1
                j = i*i
                while(j < n):
                    isPrime[j] = 0
                    j += i
        return count
