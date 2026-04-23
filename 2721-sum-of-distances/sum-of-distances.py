from collections import defaultdict

class Solution:
    def distance(self, nums):
        groups = defaultdict(list)
        
       
        for i, num in enumerate(nums):
            groups[num].append(i)
        
        res = [0] * len(nums)
       
        for indices in groups.values():
            prefix_sum = [0]
            
            for idx in indices:
                prefix_sum.append(prefix_sum[-1] + idx)
            
            n = len(indices)
            
            for i in range(n):
                idx = indices[i]
                
                left = idx * i - prefix_sum[i]
                right = (prefix_sum[n] - prefix_sum[i+1]) - idx * (n - i - 1)
                
                res[idx] = left + right
        
        return res