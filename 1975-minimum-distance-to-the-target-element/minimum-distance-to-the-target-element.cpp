class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n = nums.size();
        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (nums[i] == target) {
                int d = abs(i - start);
                ans = min(ans, d);
                if (ans == 0) break;
            }
        }
        return ans;
    }
};
