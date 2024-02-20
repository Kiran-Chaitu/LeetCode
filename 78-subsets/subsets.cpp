class Solution {
public:
    set<vector<int>> v;
    void subset(int ind,int size,vector<int> &nums,vector<int> ans){
        if(ind>=size){
            v.insert(ans);
            return;
        }
        ans.push_back(nums[ind]);
        subset(ind+1,size,nums,ans);
        ans.pop_back();
        subset(ind+1,size,nums,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        subset(0,nums.size(),nums,{});
        vector<vector<int>> fun;
        for(auto i : v){
            fun.push_back(i);
        }
        return fun;
    }
};