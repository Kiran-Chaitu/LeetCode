class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int,vector<int>> mp;
        int n = nums.size();
        for(int i = 0; i < n ; i++){
            mp[nums[i]].push_back(i);
        }
        int ans = 0;
        for(auto i: mp){
            int f = i.second[0] , l = i.second.back();
            bool temp = true;
            for(int j = f ; j <= l ; j++){
                if(nums[j] != i.first){
                    temp = false;
                    break;
                }
            }
            if(temp) ans++;
        }
        return ans;
    }
};