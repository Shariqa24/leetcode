class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp;
        unordered_set<char> used;

        for (int i = 0; i < s.size(); i++) {

            if (mp.count(s[i])) {
                if (mp[s[i]] != t[i]) {
                    return false;
                }
            }

           
            else {
                if (used.count(t[i])) {
                    return false;
                }

                mp[s[i]] = t[i];
                used.insert(t[i]);
            }
        }

        return true;
    }
};