class Solution {
public:
    bool searchInRow(vector<vector<int>>& mat, int target,int row){
         int n=mat[0].size();
         int st=0,end=n-1;
         while(st<=end){
            int mid=st+(end-st)/2;
            if (target==mat[row][mid]){
                return true;
            }else if(target>mat[row][mid]){
                 st=mid+1;
            }else{
                end=mid-1;
            }
         }return false;
    }
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m=mat.size(),n=mat[0].size();
        int stRow=0,endRow=m-1;
        while(stRow<=endRow){
            int mid=stRow+(endRow-stRow)/2;

            if(target>=mat[mid][0] && target<=mat[mid][n-1]){
            return searchInRow(mat,target,mid);
            }else if(target>=mat[mid][n-1]){
                stRow=mid+1;
            }else{
                endRow=mid-1;
            }
        }
        return false;
    }
};