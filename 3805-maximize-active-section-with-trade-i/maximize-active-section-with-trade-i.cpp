class Solution {
public:
    int maxActiveSectionsAfterTrade(string s){
        int n = s.size();

        s = "1" + s + "1";

        vector<pair<char, int>> groups;
        for (char c : s) {
            if (groups.empty() || groups.back().first != c)
                groups.push_back({c, 1});
            else
                groups.back().second++;
        }

        int ones = 0;
        for (char c : s)
            if (c == '1')
                ones++;

        
        ones -= 2;

        int ans = ones;

        for (int i = 1; i + 1 < groups.size(); i++) {
           
            if (groups[i].first == '1' &&
                groups[i - 1].first == '0' &&
                groups[i + 1].first == '0') {

                int gain = groups[i - 1].second + groups[i + 1].second;
                ans = max(ans, ones + gain);
            }
        }

        return ans;
    }
};