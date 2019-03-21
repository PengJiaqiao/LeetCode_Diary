class Solution:
    def calculate(self, s: str) -> int:
        RPN, operator = [], []
        num_begin = None
        for i in range(0, len(s)):
            if s[i] <= '9' and s[i] >= '0': 
                if i > 0 and s[i-1] <= '9' and s[i-1] >= '0': RPN[-1] += s[i]
                else: RPN.append(s[i])
                
            elif s[i] == '(': operator.append(s[i])
            elif s[i] == ')': 
                tmp = operator.pop()
                while tmp != '(': 
                    RPN.append(tmp)
                    tmp = operator.pop()
            elif s[i] == ' ': continue
            else: 
                if operator and operator[-1] != '(': RPN.append(operator.pop())
                operator.append(s[i])
        while operator: RPN.append(operator.pop())
        return self.evalRPN(RPN)
        
    def evalRPN(self, tokens: List[str]) -> int: # 150. Evaluate Reverse Polish Notation
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
