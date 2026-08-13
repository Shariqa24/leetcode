class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        
        LSI={}
        Right=0
        n=len(s)
        Left=0
        max_length=0
        while Right<n:
            ch=s[Right]
            if ch in LSI:
                if LSI[ch]>=Left:
                    Left=LSI[ch]+1
            LSI[ch]=Right
            max_length=max(max_length,Right-Left+1)
            Right+=1
        return max_length