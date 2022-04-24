'''
@functools.lru_cache(maxsize=128, typed=False)：
一个为函数提供缓存功能的装饰器，缓存 maxsize 组传入参数，
在下次以相同参数调用时直接返回上一次的结果。用以节约高开销或 I/O 函数的调用时间。
'''

class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        wordDict = sorted(wordDict, reverse=True)
        import functools
        @functools.lru_cache(None)
        def backtrack(pos):
            if pos >= len(s):
                return True
            for word in wordDict:
                if word == s[pos:pos+len(word)]:
                    if backtrack(pos+len(word)):
                        return True
            return False
        return backtrack(0)

class Solution1:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        n = len(s)
        import functools
        @functools.lru_cache(None)
        def backtrack(pos):
            if pos >= n:
                return True
            for i in range(pos+1, n+1):
                if s[pos:i] in wordDict:
                    if backtrack(i):
                        return True
            return False
        return backtrack(0)


