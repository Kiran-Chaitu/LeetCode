class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = 0 , i = 0 , j = 0;
        long long n = prices.size();
        while(j < n-1){
            while(j <n-1 and prices[j] - prices[j+1] == 1) j++;
            if(j >= n-1) break;
            long long k = j-i+1;
            long long temp = (k*(k+1))/2;
            // cout<<temp<<endl;
            ans+=temp;
            i=j+1;
            j++;
        }
        long long k = j-i+1;
        ans += (k*(k+1))/2;
        return ans;
    }
};