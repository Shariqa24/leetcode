class Solution {
public:
    static constexpr int MOD = 1e9 + 7;
    int memo[205][201][201];
    int n;

    int dfs(int i, int g1, int g2, vector<int>& nums) {
        if (i == n)
            return (g1 > 0 && g2 > 0 && g1 == g2);

        int &res = memo[i][g1][g2];
        if (res != -1) return res;

        long long ans = dfs(i + 1, g1, g2, nums);

        int ng1 = (g1 == 0) ? nums[i] : gcd(g1, nums[i]);
        ans += dfs(i + 1, ng1, g2, nums);

        int ng2 = (g2 == 0) ? nums[i] : gcd(g2, nums[i]);
        ans += dfs(i + 1, g1, ng2, nums);

        return res = ans % MOD;
    }

    int subsequencePairCount(vector<int>& nums) {
        n = nums.size();
        memset(memo, -1, sizeof(memo));
        return dfs(0, 0, 0, nums);
    }
};