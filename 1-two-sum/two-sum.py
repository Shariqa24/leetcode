class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        n=len(nums)
        freq={}
        for i in range(0,n):
            need=target-nums[i]
            if need in freq:
                return [freq[need],i]
            freq[nums[i]]=i