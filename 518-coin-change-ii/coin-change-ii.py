class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        n = len(coins)

        dp = [[0] * (amount + 1) for _ in range(n + 1)]

        for i in range(n + 1):
            dp[i][0] = 1

        for i in range(n - 1, -1, -1):
            for j in range(1, amount + 1):

                take = 0
                if coins[i] <= j:
                    take = dp[i][j - coins[i]]

                nott = dp[i + 1][j]

                dp[i][j] = take + nott

        return dp[0][amount]