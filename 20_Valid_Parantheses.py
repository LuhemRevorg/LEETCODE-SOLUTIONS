class Solution:
    def isValid(self, s: str) -> bool:
        stck = []
        for i in s:
            if i == '(' or i == '{' or i == '[':
                stck.append(i)
            elif i == ')' or i == '}' or i == ']':
                if len(stck) == 0:
                    return False
                elif i == ')':
                    if stck.pop() != '(':
                        return False
                elif i == ']':
                    if stck.pop() != '[':
                        return False
                elif i == '}':
                    if stck.pop() != '{':
                        return False
        if len(stck) == 0:
            return True
        return False        