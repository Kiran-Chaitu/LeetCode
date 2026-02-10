class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int maxi = 0 , n = nums.size();
        for(int i = 0; i < n;i++){
            unordered_map<int,int> mp;
            int ev = 0, od =0;
            for(int j = i ;j < n ; j++){
                if(mp.find(nums[j])==mp.end()){
                    if(nums[j]&1) od++;
                    else ev++;
                    mp[nums[j]]++;
                }
                if(ev == od){
                    maxi = max(maxi , j - i +1);
                }
            }
        }
        return maxi;
    }
};