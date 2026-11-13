class Solution:
    def maxSubArray(self, nums: list[int]) -> int:
       max_Sum=nums[0]
       res=nums[0]
       for i in range(1,len(nums)):
        max_Sum=max(nums[i],max_Sum+nums[i])
        res=max(res,max_Sum)
       return res
    