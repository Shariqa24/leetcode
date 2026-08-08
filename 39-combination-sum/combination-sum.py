from typing import List

class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        ans = []
        substr = []
        
        def solve(i, rem_target):
            if rem_target == 0:
                ans.append(substr.copy())
                return
            if i < 0 or rem_target < 0:
                return
            
            substr.append(candidates[i])
            solve(i, rem_target - candidates[i])
            substr.pop()
            
            solve(i - 1, rem_target)
            
        solve(len(candidates) - 1, target)
        return ans
