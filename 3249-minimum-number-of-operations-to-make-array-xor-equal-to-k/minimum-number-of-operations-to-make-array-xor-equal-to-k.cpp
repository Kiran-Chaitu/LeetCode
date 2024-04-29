class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int ans=0;
        for(auto x:nums){
            ans=ans^x;
        }
        ans=ans^k;
        int res=0;
        while(ans>0){
            if(ans&1)
            res++;
            ans=ans>>1;
        }
        return res;
    }
};