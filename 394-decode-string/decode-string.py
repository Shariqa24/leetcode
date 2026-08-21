class Solution:
    def decodeString(self, s: str) -> str:
        numStack = []
        strStack = []

        currNum = 0
        currStr = ""

        for ch in s:
            if ch.isdigit():
                currNum = currNum * 10 + int(ch)

            elif ch == '[':
                numStack.append(currNum)
                strStack.append(currStr)

                currNum = 0
                currStr = ""

            elif ch == ']':
                repeat = numStack.pop()
                prevStr = strStack.pop()

                currStr = prevStr + repeat * currStr

            else:
                currStr += ch

        return currStr