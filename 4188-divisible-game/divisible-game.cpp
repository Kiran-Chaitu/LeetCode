#define ll long long
class Solution {
public:
    int mod = 1e9+7;
    ll solver(vector<int> &nums ,int k){
        ll cur = LLONG_MIN , maxi = LLONG_MIN;
        for(int i : nums){
            ll val = (i%k == 0) ? i : -1LL * i;
            if(cur < 0) cur = val;
            else cur += val;
            maxi = max(maxi , cur);
        }
        return maxi;
    }
    int divisibleGame(vector<int>& nums) {
        int maxi = LLONG_MIN;
        for(auto i : nums) maxi = max(maxi , i);
        unordered_set<int> st;
        for(int i : nums){
            for(int j = 1 ;  j * j <= i; j++){
                if(i%j == 0){
                    if(j  >1) st.insert(j);
                    int temp = i/j;
                    if(temp > 1) st.insert(temp);
                }
            }
        }
        st.insert(maxi+1);
        vector<int> ans(st.begin() , st.end());
        sort(ans.begin() , ans.end());
        ll bst = LLONG_MIN;
        int bk = INT_MAX;
        for(int i : ans){
            ll s = solver(nums,i);
            if(s > bst){
                bst = s;
                bk = i;
            }else if(s == bst and i < bk){
                bk = i;
            }
        }
        ll res = ((bst%mod) + mod)%mod;
        res = (res * bk)%mod;
        return (int)res;
    }
};