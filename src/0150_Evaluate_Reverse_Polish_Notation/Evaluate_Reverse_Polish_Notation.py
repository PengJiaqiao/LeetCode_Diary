class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        operator = {
            '+': lambda a, b: a + b,
            '-': lambda a, b: a - b,
            '*': lambda a, b: a * b,
            '/': lambda a, b: (a // b) + 1 if a // b < 0 and a % b != 0 else a // b
        }
        
        stack = []
        for token in tokens:
            if token in operator:
                r, l = stack.pop(), stack.pop()
                stack.append(operator[token](l, r))
            else: stack.append(int(token))
        return stack.pop()
