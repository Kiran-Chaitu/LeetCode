class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int maxi=INT_MIN,n=prices.size();
        vector<int> v(n);
        for(int i=n-1;i>=0;i--){
            if(maxi < prices[i]) maxi = prices[i];
            v[i] = maxi;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans = max(ans,v[i] - prices[i]);
        }
        return ans;
    }
};