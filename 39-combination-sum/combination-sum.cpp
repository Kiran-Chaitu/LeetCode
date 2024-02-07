class Solution {
public:
    vector<vector<int>> ans;
    void solver(vector<int> v,int ind,int n,int t,int sum,vector<int> res){
        if(ind>=n and sum!=t)   return;
        else if(sum==t){
            ans.push_back(res);
            return;
        }
        else if(sum>t) return;
        res.push_back(v[ind]);
        solver(v,ind,n,t,sum+v[ind],res);
        res.pop_back();
        solver(v,ind+1,n,t,sum,res);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> res;
        sort(candidates.begin(),candidates.end());
        solver(candidates,0,candidates.size(),target,0,res);
        return ans;
    }
};