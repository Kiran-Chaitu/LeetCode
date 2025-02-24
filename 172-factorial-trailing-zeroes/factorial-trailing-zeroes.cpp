vector<int> dp(1e4+1,0);
class Solution {
public:
    void solver(){
        long long c=0;
        for(int i=1;i<1e4+1; i++){
            long long k = i ;
            while(k>0 and k%5==0){
                c++;
                k/=5;
            }
            dp[i] = c;
        }
        
    }
    int trailingZeroes(int n) {
        if(dp[5]==0){
            solver();
        }
        return dp[n];

    }
};