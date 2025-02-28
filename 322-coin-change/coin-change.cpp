class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount ==0) return 0;
        vector<int> dp(amount+1 ,-1);
        for(int i=0;i<coins.size();i++){
            if(coins[i] <= amount)    dp[coins[i]]=1;
        }
        for(int i=1;i<=amount;i++){
            if(dp[i]==1) continue;
            int mini = INT_MAX;
            for(int j=0;j<coins.size();j++){
                if(i - coins[j] > 0 and dp[i-coins[j]]!=-1){
                    mini = min(mini , 1 + dp[i - coins[j]]);
                }
            }
            if(mini!=INT_MAX) dp[i] = mini;
        }
        return dp[amount];
    }
};