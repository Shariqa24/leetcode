class Solution {
public:
    bool isPalindrome(int x) {
        std::string str = std::to_string(x); 
        int n=str.size();
        int j=n-1;
        for (int i=0;i<n/2;i++){
            if(str[i]!=str[j]){
                return false;
            }
            j-=1;
        }
        return true;
    }
};