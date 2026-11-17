class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        vector<bool> prime(n+1 , true);
        prime[0] = false , prime[1] = false;
        for(int i = 2; i<=sqrt(n); i++){
            if(prime[i]){
                for(int j = i*i; j<=n ; j+=i){
                    prime[j] = false;
                }
            }
        }
        vector<int> ans;
        for(int i = 2 ; i<=n ; i++){
            if(prime[i]) ans.push_back(i);
        }
        int st = 0 , end = ans.size()-1;
        vector<vector<int>> v;
        while(st <= end){
            int sum = ans[st] + ans[end];
            if(sum == n){
                v.push_back({ans[st++] , ans[end--]});
            }else if(sum < n){
                st++;
            }else{
                end--;
            }
        }
        return v;
    }
};