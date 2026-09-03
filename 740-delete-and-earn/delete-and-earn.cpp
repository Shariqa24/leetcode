class Solution {
public:

    int solve(int i, vector<int>& points, vector<int>& dp) {

        if (i >= points.size()) {
            return 0;
        }

        if (dp[i] != -1) {
            return dp[i];
        }

        // Don't take current number
        int notTake = solve(i + 1, points, dp);

        // Take current number
        int take = points[i] + solve(i + 2, points, dp);

        return dp[i] = max(take, notTake);
    }

    int deleteAndEarn(vector<int>& nums) {

        int maxi = *max_element(nums.begin(), nums.end());

        // points[x] = total points obtained by taking x
        vector<int> points(maxi + 1, 0);

        for (int x : nums) {
            points[x] += x;
        }

        vector<int> dp(maxi + 1, -1);

        return solve(0, points, dp);
    }
};