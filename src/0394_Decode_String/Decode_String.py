class Solution:
    def decodeString(self, s: str) -> str:
        stack, num = [["", ""]], ""
        for char in s:
            if char.isdigit(): num += char
            elif char == "[": 
                stack.append(["", num])
                num = ""
            elif char == "]":
                tmp = stack.pop()
                stack[-1][0] += tmp[0] * int(tmp[1])
            else: stack[-1][0] += char
        return stack[0][0]
