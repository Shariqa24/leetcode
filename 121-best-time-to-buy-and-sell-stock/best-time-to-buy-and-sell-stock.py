class Solution:
    def maxProfit(self, prices):
        min_val = prices[0]
        max_profit = 0

        for curr in prices:
            profit = curr - min_val
            max_profit = max(max_profit, profit)
            min_val = min(min_val, curr)

        return max_profit