#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num_map; 
        for (int i = 0; i < nums.size(); ++i) {
            int diff = target - nums[i];
            if (num_map.find(diff) != num_map.end()) {
                return {num_map[diff], i};
            }
            num_map[nums[i]] = i;
        }
        return {}; 
    }
};
