class Solution:
    def numDecodings(self, s: str) -> int:
        if(s[0] == '0'):
            return 0
        f1 = 1
        f2 = 1
        f3 = 0
        for i in range(1, len(s) + 1):
            f3 = 0
            if s[i - 1] != '0':
                f3 += f2
            if i > 1 and s[i - 2] != '0' and int(s[i-2:i]) <= 26:
                f3 += f1
            f1 = f2
            f2 = f3
        return f3
