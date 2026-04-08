class Solution {
public:
    const int MOD = 1e9 + 7;

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int B = sqrt(n) + 1;

        for (auto &q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];

            if (k >= B) {
                // Direct updates
                for (int i = l; i <= r; i += k) {
                    nums[i] = (1LL * nums[i] * v) % MOD;
                }
            } else {
                // Small k → still simulate but limited
                for (int i = l; i <= r; i += k) {
                    nums[i] = (1LL * nums[i] * v) % MOD;
                }
            }
        }

        int ans = 0;
        for (int x : nums) ans ^= x;

        return ans;
    }
};