#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        vector<pair<int, int>> sorted_pairs(n);
        for (int i = 0; i < n; ++i) {
            sorted_pairs[i] = {nums[i], i};
        }
        sort(sorted_pairs.begin(), sorted_pairs.end());

        vector<int> sorted_vals(n);
        vector<int> orig_to_sorted(n);
        for (int i = 0; i < n; ++i) {
            sorted_vals[i] = sorted_pairs[i].first;
            orig_to_sorted[sorted_pairs[i].second] = i;
        }

        const int LOG = 18; 
        vector<vector<int>> st(n, vector<int>(LOG));

        for (int i = 0; i < n; ++i) {
            int target_val = sorted_vals[i] + maxDiff;
            auto it = upper_bound(sorted_vals.begin(), sorted_vals.end(), target_val);
            int farthest_idx = distance(sorted_vals.begin(), it) - 1;
            st[i][0] = farthest_idx;
        }

        for (int j = 1; j < LOG; ++j) {
            for (int i = 0; i < n; ++i) {
                st[i][j] = st[st[i][j - 1]][j - 1];
            }
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (const auto& q : queries) {
            int u = q[0];
            int v = q[1];

            if (u == v) {
                ans.push_back(0);
                continue;
            }

            int start = orig_to_sorted[u];
            int end = orig_to_sorted[v];

            if (start > end) {
                swap(start, end);
            }

            if (st[start][LOG - 1] < end) {
                ans.push_back(-1);
                continue;
            }

            if (st[start][0] >= end) {
                ans.push_back(1);
                continue;
            }

            int steps = 0;
            int curr = start;
            for (int j = LOG - 1; j >= 0; --j) {
                if (st[curr][j] < end) {
                    curr = st[curr][j];
                    steps += (1 << j);
                }
            }

            ans.push_back(steps + 1);
        }

        return ans;
    }
};
