class Solution {
public:
    int solver(int i , vector<vector<int>> &dp , vector<int> &stones , int target , int sum , int total){
        if(i==stones.size() or sum >= target ){
            return abs(2*sum - total);
        }
        if(dp[i][sum]!=-1) return dp[i][sum];
        dp[i][sum] = min(solver(i+1,dp,stones , target,sum+stones[i] , total) , 
                         solver(i+1 , dp,stones , target,sum,total ));
        return dp[i][sum];
    }
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        vector<vector<int>> dp( n+1 , vector<int>(3001,-1));
        int sum=0;
        for(auto i:stones) sum+=i;
        int target = ceil((double)(sum)/2);
        // cout<<target<<endl;
        int k = solver(0 , dp , stones , target ,0 , sum );
        return k;
    }
};