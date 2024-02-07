class Solution {
public:
    vector<vector<int>> ans;
    void solver(int i,int n,int k,vector<int> &nums,vector<int> &res){
            if(i==n){
                if(res.size()==k)    ans.push_back(res);
                return;
            }
            res.push_back(nums[i]);
            solver(i+1,n,k,nums,res);
            res.pop_back();
            solver(i+1,n,k,nums,res);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> res;
        vector<int> nums;
        for(int i=1;i<=n;i++){
            nums.push_back(i);
        } 
        solver(0,n,k,nums,res);
        return ans;
    }
};