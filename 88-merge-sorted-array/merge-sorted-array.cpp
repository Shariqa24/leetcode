class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>result;
        for(int i=0;i<m;i++){
            result.push_back(nums1[i]);
        }
        for(int j=0;j<n;j++){
            result.push_back(nums2[j]);
        }
        sort(result.begin(),result.end());
    
        for(int k=0;k<m+n;k++){
            nums1[k]=result[k];
    }
}};