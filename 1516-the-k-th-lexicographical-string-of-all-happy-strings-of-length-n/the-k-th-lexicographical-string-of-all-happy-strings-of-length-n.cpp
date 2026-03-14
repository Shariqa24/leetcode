class Solution {
public:
    
    void solve(int n, string curr, vector<string>& ans) {
        
        if(curr.size() == n){
            ans.push_back(curr);
            return;
        }
        
        for(char c : {'a','b','c'}) {
            if(curr.empty() || curr.back() != c){
                solve(n, curr + c, ans);
            }
        }
    }
    
    string getHappyString(int n, int k) {
        
        vector<string> ans;
        
        solve(n, "", ans);
        
        if(ans.size() < k) return "";
        
        return ans[k-1];
    }
};