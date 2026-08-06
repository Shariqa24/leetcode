class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        n=len(coins)
        memo=[[-1]*(amount+1) for _ in range (n+1)]

        def solve(i,ts):
            if(ts==0):
                return 1
            if (i==n):
                return 0

            if memo[i][ts]!=-1:
                return memo[i][ts]  

            take=0

            if coins[i]<=ts:
                take=solve(i,ts-coins[i])   

            nott=solve(i+1,ts)

            memo[i][ts]= nott+take
            return memo[i][ts]

        return solve(0,amount)    

                

        