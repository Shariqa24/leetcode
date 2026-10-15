class Solution:
    def sumCounts(self, nums: List[int]) -> int:
        res = 0
        for i in range(len(nums)):
            unique_elements = set()
            for j in range(i, len(nums)):
                unique_elements.add(nums[j])
                res += len(unique_elements) ** 2
        return res
