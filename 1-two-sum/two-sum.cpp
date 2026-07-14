class Solution {
public:
    vector<int> twoSum(vector<int>& n, int target) {
      unordered_map<int,int>mp;
      for(int i=0;i<n.size();i++){
      int need=target-n[i];
         if(mp.count(need)){
            return {mp[need],i};
    }
   mp[n[i]]=i;
 }
       return {};
    }
};