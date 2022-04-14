class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        res = [[1]]
        for i in range(numRows-1):
            tmpRow = [1]
            for j in range(i):
                tmpRow.append(res[i][j] + res[i][j+1])
            tmpRow.append(1)
            res.append(tmpRow)
        return res
