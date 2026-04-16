#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int, vector<int>> pos;
        int n = nums.size();
        
        // Store indices
        for (int i = 0; i < n; i++) {
            pos[nums[i]].push_back(i);
        }
        
        vector<int> result;
        
        for (int index : queries) {
            int val = nums[index];
            vector<int>& arr = pos[val];
            int m = arr.size();
            
            if (m == 1) {
                result.push_back(-1);
                continue;
            }
            
            int i = lower_bound(arr.begin(), arr.end(), index) - arr.begin();
            
            int prev = arr[(i - 1 + m) % m];
            int next = arr[(i + 1) % m];
            
            int d1 = abs(prev - index);
            int d2 = abs(next - index);
            
            int dist1 = min(d1, n - d1);
            int dist2 = min(d2, n - d2);
            
            result.push_back(min(dist1, dist2));
        }
        
        return result;
    }
};