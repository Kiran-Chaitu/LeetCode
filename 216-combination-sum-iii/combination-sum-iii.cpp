class Solution {
public:
    set<vector<int>> st;
    void solver(vector<int> v,int ind,int n,int t,int sum,vector<int> res,int k){
        if(ind>=n and sum!=t)   return;
        else if(sum==t){
            if(res.size()==k)   st.insert(res);
            return;
        }
        else if(sum>t) return;
        res.push_back(v[ind]);
        solver(v,ind+1,n,t,sum+v[ind],res,k);
        res.pop_back();
        solver(v,ind+1,n,t,sum,res,k);
    }
    vector<vector<int>> combinationSum3(int k, int target) {
        vector<int> res;
        vector<int> nums={1,2,3,4,5,6,7,8,9};
        vector<vector<int>> ans;
        solver(nums,0,nums.size(),target,0,res,k);
        for(auto i : st){
            ans.push_back(i);
        }
        return ans;
    }
};