class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        requisites = [[] for i in range(numCourses)]
        for pair in prerequisites:
            requisites[pair[0]].append(pair[1])  # 整理一下prerequisites数组

        can = [-1] * numCourses
        courseOrder = []
        def dfs(pos):
            if can[pos] == -1:  # -1, 之前没有验证过，进行dfs
                can[pos] = 0 
                for i in requisites[pos]:
                    if not dfs(i):
                        return False
                can[pos] = 1
                courseOrder.append(pos)
                return True
            elif can[pos] == 0:  # 0, 表示本次验证过，构成闭环
                return False
            else:  # 1, 表示之前已经验证过，不构成闭环
                return True

        for i in range(numCourses):
            if not dfs(i):
                return []
        return courseOrder
