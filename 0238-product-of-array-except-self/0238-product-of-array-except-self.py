class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        product_value = 1
        zero_count = 0
        n = len(nums)
        for i in range(len(nums)):
            if(nums[i]==0):
                zero_count+=1
            else:
                product_value*=nums[i]

        if (zero_count>1):
            return [0]*n
        
        ans = [0]*n
        if(zero_count==1):
            for i in range(n):
                if(nums[i]==0):
                    ans[i]=product_value
            return ans
        
        for i in range(n):
            ans[i]=product_value//nums[i]
        return ans
        