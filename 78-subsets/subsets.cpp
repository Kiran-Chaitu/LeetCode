class Solution {
public:
    vector<vector<int>> ans={};
    set<vector<int>> st;
    void solver(vector<int> &v ,int i, int n , vector<int> &nums){
        if(i>=n){
            st.insert(v);
            return ;
        }
        v.push_back(nums[i]);
        solver(v,i+1 , n , nums);
        v.pop_back();
        solver(v,i+1 , n  ,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n= nums.size();
        vector<int> v={};
        solver(v ,0 , n ,nums);
        for(auto i:st) ans.push_back(i);
        return ans;
    }
};