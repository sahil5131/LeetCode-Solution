class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        nums1=[]
        nums2=[]
        for num in nums:
            if num<0:
                nums1.append(num)
            else:
                nums2.append(num)
        for i in range(len(nums1)):
            nums[2*i]=nums2[i]
            nums[2*i+1]=nums1[i]
        return nums

        