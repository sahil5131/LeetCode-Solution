class Solution:
    def divideArray(self, nums: List[int], k: int) -> List[List[int]]:
        nums.sort()
        result = []
        n = len(nums)
        for i in range(0,n-1,3):
            if nums[i+2]-nums[i] > k:
                return []
            result.append([nums[i], nums[i+1], nums[i+2]])
        return result