class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashMap = {}
        for i in range(len(nums)):
            subNum = target-nums[i]
            if subNum in hashMap:
                return [hashMap[subNum], i]
            else:
                hashMap[nums[i]]=i
        return -1