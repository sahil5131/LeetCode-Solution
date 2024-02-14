class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        count=1
        n = len(nums)
        ans=nums[0]
        for i in range(1,n,1):
            if(count==0):
                ans=nums[i]
            if(ans==nums[i]):
                count+=1
            else:
                count-=1
                
        return ans