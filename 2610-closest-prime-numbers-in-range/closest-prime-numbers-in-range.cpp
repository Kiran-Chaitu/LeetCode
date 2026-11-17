class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> prime(right+1,true);
        prime[0] = false , prime[1] = false;
        for(int i = 2; i<= sqrt(right); i++){
            if(prime[i]){
                for(int j = i*i; j<=right; j+=i){
                    prime[j] = false;
                }
            }
        }
        vector<int> v;
        for(int i = left ;i <= right; i++) if(prime[i]) v.push_back(i);
        vector<int> ans = {-1,-1};
        int mini = INT_MAX;
        for(int i = 1; i<v.size() ; i++){
            if(v[i] - v[i-1] < mini){
                ans = {v[i-1] , v[i]};
                mini = v[i] - v[i-1];
            }
        }
        return ans;
    }
};