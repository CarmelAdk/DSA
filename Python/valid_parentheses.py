class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        parentheses = {')': '(', '}': '{', ']': '['}
        stack = []

        for el in s: 
            if el in parentheses:
                if(len(stack) == 0):
                    return False
                else:
                    if(parentheses[el] != stack.pop(0)):
                        return False
            else:
                stack.insert(0, el)
        return len(stack) == 0