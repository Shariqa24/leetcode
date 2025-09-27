
from typing import List
import itertools
import math

class Solution:
    def largestTriangleArea(self, points: List[List[int]]) -> float:
        def area(a,b,c):
          
            return 0.5 * abs((b[0]-a[0])*(c[1]-a[1]) - (c[0]-a[0])*(b[1]-a[1]))
        ans = 0.0
        n = len(points)
     
        for i in range(n):
            for j in range(i+1, n):
                for k in range(j+1, n):
                    ans = max(ans, area(points[i], points[j], points[k]))
        return ans
