class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int answer=0;
        for(int i=left;i<=right;i++){
           int  count=0;
            int n=i;
            while(n>0){
                if(n%2==1){
                    count++;
                }
                n=n/2;
            }
            if(count==2||count==3|| count==5||count==7||
            count==11||count==13||count==17||count==19){
                answer++;
            }
            }
    return answer;
    }
};