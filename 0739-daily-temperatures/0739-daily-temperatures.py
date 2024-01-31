class Solution:
    def dailyTemperatures(self, tempratures: List[int]) -> List[int]:
        stack = []
        n = len(tempratures)
        result = []
        for i in range(n-1,-1,-1):
            
            if not len(stack):
                result.append(0)
                stack.append([tempratures[i], i])
            elif stack[-1][0]>tempratures[i]:
                result.append(stack[-1][1]-i)
                stack.append([tempratures[i], i])
            else:
                while(len(stack) and tempratures[i]>=stack[-1][0]):
                    stack.pop()
                if len(stack)>0:
                    result.append(stack[-1][1]-i)
                    stack.append([tempratures[i], i])
                else:
                    result.append(0)
                    stack.append([tempratures[i], i])
            print(stack[-1][0], " ", stack[-1][1])
        result.reverse()
        return result
            
        