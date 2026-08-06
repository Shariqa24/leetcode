class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        n=len(coins)
        memo={}

        def solve(i,ts):
            if(ts==0):
                return 1
            if (i==n):
                return 0

            if (i,ts) in memo:
                return memo [(i,ts)]    

            take=0

            if coins[i]<=ts:
                take=solve(i,ts-coins[i])   

            nott=solve(i+1,ts)

            memo[(i,ts)]= nott+take
            return memo[(i,ts)]

        return solve(0,amount)    

                

        