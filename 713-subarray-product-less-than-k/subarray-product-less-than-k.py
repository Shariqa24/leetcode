class Solution:
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
        if k<=1:
            return 0
        cnt=0
        l=0
        pr=1
        for r in range(len(nums)):
            pr=pr*nums[r]
            while pr>=k:
                pr//=nums[l]
                l+=1
            cnt+=(r-l+1)
        return cnt