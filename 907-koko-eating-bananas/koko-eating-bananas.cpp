class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        int ans=high;
        while(low<=high){
            long long hours=0;
            long long mid=low+(high-low)/2;
        
        for(int pile:piles){
            hours+=(pile+mid-1)/mid;
        }
        if (hours<=h){
            ans=mid;
            high=mid-1;
        }
        else{
        low=mid+1;
    } }return ans;
    } 
};