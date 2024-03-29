class Solution {
public:
    set<vector<int>> sv;
    void subs(vector<int> v,int n,int ind,vector<int> ans){
        //ios_base::sync_with_stdio(0);
        if(ind>=n){
            sv.insert(ans);
            return;
        }
        ans.push_back(v[ind]);
        subs(v,n,ind+1,ans);
        ans.pop_back();
        subs(v,n,ind+1,ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        //ios_base::sync_with_stdio(0);
        sort(nums.begin(),nums.end());
        subs(nums,nums.size(),0,{});
        vector<vector<int>> v;
        for(auto i : sv) v.push_back(i);
        return v;
    }
};