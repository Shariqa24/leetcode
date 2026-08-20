from typing import List

class Solution:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:
        freq = {}
        freq[0] = 1 
        Prefix = 0
        count = 0
        
        for i in range(len(nums)): 
            Prefix = Prefix + nums[i]
            rem = Prefix % k
            
            
            if rem < 0:
                rem = rem + k
                
            if rem in freq:
                count = count + freq[rem] 
                freq[rem] = freq[rem] + 1 
            else:
                freq[rem] = 1 
                
        return count 
