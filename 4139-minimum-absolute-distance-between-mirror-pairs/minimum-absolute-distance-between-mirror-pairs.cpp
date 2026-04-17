class Solution {
public:
    long long rev(long long n){
        long long ans = 0;
        while(n){
            ans = ans *10 + (n%10);
            n/=10;
        }
        return ans;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n = nums.size();
        int mini =INT_MAX;
        for(int i = 0; i < n ; i++){
            if(mp.find(nums[i])!=mp.end()){
                mini = min(i - mp[nums[i]]  , mini);
            }
            mp[rev(nums[i])] = i;
        }
        return mini == INT_MAX ? -1: mini;
    }
};