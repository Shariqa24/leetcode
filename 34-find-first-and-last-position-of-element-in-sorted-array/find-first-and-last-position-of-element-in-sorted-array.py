class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        def findBound(isFirst:bool)->int:
            low=0
            high=len(nums)-1
            bound=-1
            while low<=high:
                mid=low+(high-low)//2
                if nums[mid]==target:
                    bound=mid
                    if isFirst:
                        high=mid-1
                    else:
                        low=mid+1
                elif nums[mid]<target:
                    low=mid+1
                else:
                    high=mid-1
            return bound
        return [findBound(True),findBound(False)]