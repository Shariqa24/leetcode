class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>freq1;
        unordered_map<char,int>freq2;
        for(char ch:s){
            freq1[ch]++;
        }
        for(char ch:t){
            freq2[ch]++;
        }
        if(freq1==freq2){
            return true;
        }
        return false;
    }
};