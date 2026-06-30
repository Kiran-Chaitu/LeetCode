#define ll long long
class Solution {
public:
    ll solver(ll i , ll amount, vector<vector<ll>> &dp , vector<int> &nums){
        if(amount  == 0) return 1;
        if(amount < 0) return 0;
        if(i < 0) return 0;
        if(dp[i][amount]!=-1) return dp[i][amount];
        ll pick = 0;
        if(nums[i] <= amount) pick+=solver(i, amount - nums[i] , dp , nums);
        ll unpick = solver(i-1, amount , dp , nums);
        return dp[i][amount] =  pick + unpick;
    }
    int change(int amount, vector<int>& coins) {
        if(amount  == 0) return 1;
        ll n = coins.size();
        vector<vector<ll>> dp(n , vector<ll>(amount+1,-1));
        // vector<vector<ll>> dp(n , vector<ll>(amount+1,0));
        return solver(n-1 , amount , dp, coins);
        for(int i = 0; i < n ; i ++) dp[i][0] = 1;
        for(int i = 0; i <= amount ; i++){
            if(i%coins[0] ==0) dp[0][i] = 1;
        }
        for(ll i = 1 ; i< n ; i ++){
            for(ll j = 0; j <= amount;j++){
                ll pick = 0;
                if(coins[i] <= j) pick+=dp[i][j - coins[i]];
                ll unpick = dp[i-1][j];
                dp[i][j] = pick + unpick;
            }
        }
        return dp[n-1][amount];
    }
};