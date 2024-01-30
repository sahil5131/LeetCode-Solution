class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        operators = {'+': lambda x, y: x + y,
                     '-': lambda x, y: x - y,
                     '*': lambda x, y: x * y,
                     '/': lambda x, y: int(x / y)}

        for token in tokens:
            if token in operators:
                stack.append(operators[token](stack.pop(-2), stack.pop()))
            else:
                stack.append(int(token))

        return stack[0]
