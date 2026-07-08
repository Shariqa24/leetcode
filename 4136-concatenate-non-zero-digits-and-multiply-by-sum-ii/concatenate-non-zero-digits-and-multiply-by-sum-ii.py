class Solution:
    def sumAndMultiply(self, s: str, queries: list[list[int]]) -> list[int]:
        MOD = 10**9 + 7
        n = len(s)
        
        pow10 = [0] * (n + 1)
        pow10[0] = 1
        
        idx = [0] * (n + 1)
        x = [0] * (n + 1)
        total = [0] * (n + 1)
        
        for i in range(n):
            d = ord(s[i]) - ord('0')
            pow10[i+1] = (pow10[i] * 10) % MOD
            
            if d != 0:
                idx[i+1] = idx[i] + 1
                x[i+1] = (x[i] * 10 + d) % MOD
            else:
                idx[i+1] = idx[i]
                x[i+1] = x[i]
                
            total[i+1] = total[i] + d
            
        ans = []
        for l, r in queries:
            digit_sum = total[r+1] - total[l]
            non_zero_count = idx[r+1] - idx[l]
            val = (x[r+1] - x[l] * pow10[non_zero_count]) % MOD
            ans.append((val * digit_sum) % MOD)
            
        return ans
