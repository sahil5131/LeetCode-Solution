class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        n = len(tokens)
        stack = []
        for i in range(n):
            if not len(stack):
                stack.append(int(tokens[i]))
            elif tokens[i]=='+' or tokens[i]=='-' or tokens[i]=='*' or tokens[i]=='/':
                a = stack.pop()
                b = stack.pop()
                if tokens[i]=='+':
                    stack.append(b+a)
                elif tokens[i]=='-':
                    stack.append(b-a)
                elif tokens[i] == '*':
                    stack.append(b*a)
                else: 
                    stack.append(int(b/a))
            else :
                stack.append(int(tokens[i]))
        return stack.pop()