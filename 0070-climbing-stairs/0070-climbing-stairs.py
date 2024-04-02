class Solution:
    def climbStairs(self, n: int) -> int:
        n1=1
        n2=2
        if n==1:
            return 1
        if n==2:
            return 2
        ans=0
        for i in range(2, n):
            ans=n1+n2
            n1=n2
            n2=ans
        return ans
        