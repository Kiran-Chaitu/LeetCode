class Solution {
public:
    set<vector<int>> st;
    void solver(vector<int> v,int ind,int n,int t,int sum,vector<int> res){
        if(ind>=n and sum!=t)   return;
        else if(sum==t){
            st.insert(res);
            return;
        }
        else if(sum>t) return;
        res.push_back(v[ind]);
        solver(v,ind+1,n,t,sum+v[ind],res);
        while(ind+1 < n and v[ind]==v[ind+1]) ind++;
        res.pop_back();
        solver(v,ind+1,n,t,sum,res);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> res;
        vector<vector<int>> ans;
        sort(candidates.begin(),candidates.end());
        solver(candidates,0,candidates.size(),target,0,res);
        for(auto i : st){
            ans.push_back(i);
        }
        return ans;
    }
};