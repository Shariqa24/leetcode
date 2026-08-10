class Solution {
public:

    int solve(int i, int M, vector<int>& piles,
              vector<vector<int>>& dp,
              vector<int>& suffix) {

        int n = piles.size();

        // We can take all remaining piles
        if (i >= n)
            return 0;

        // If we can take everything
        if (2 * M >= n - i)
            return suffix[i];

        if (dp[i][M] != -1)
            return dp[i][M];

        int ans = 0;

        // Try taking X piles
        for (int X = 1; X <= 2 * M; X++) {

            int taken = suffix[i] - suffix[i + X];

            int opponent = solve(
                i + X,
                max(M, X),
                piles,
                dp,
                suffix
            );

            int current = taken +
                          suffix[i + X] -
                          opponent;

            ans = max(ans, current);
        }

        return dp[i][M] = ans;
    }

    int stoneGameII(vector<int>& piles) {

        int n = piles.size();

        // suffix[i] = total stones from i to n-1
        vector<int> suffix(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + piles[i];
        }

        vector<vector<int>> dp(
            n,
            vector<int>(n + 1, -1)
        );

        return solve(0, 1, piles, dp, suffix);
    }
};