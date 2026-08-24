class Solution:
    def minFallingPathSum(self, matrix: List[List[int]]) -> int:
        n=len(matrix)
        memo={}
        def s(i,j):
            if j<0 or j>=n:
                return float('inf')
            if(i,j) in memo:
                return memo[(i,j)]
            if i==n-1:
                return matrix[i][j]
            LD=s(i+1,j-1)
            D=s(i+1,j)
            RD=s(i+1,j+1)
            memo[(i,j)] = matrix[i][j]+min(LD,D,RD)
            return memo[(i,j)]
        return min(s(0,j) for j in range(n))
