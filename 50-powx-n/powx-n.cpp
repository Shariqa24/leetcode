class Solution {
public:
    double myPow(double x, int n) {
        long binNum=n;
        if(n<0){
            x=1/x;
            binNum=-binNum;
        }
        double ans=1;
        while(binNum>0){
            if(binNum%2==1){
                ans*=x;
            }x*=x;
          binNum/=2;
        } return ans;
    }
};