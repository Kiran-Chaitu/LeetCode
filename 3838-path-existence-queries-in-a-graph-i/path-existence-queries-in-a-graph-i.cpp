class DSU{
    private:
        vector<int> par , size;
    public:
        DSU(int n){
            par.resize(n+1);
            size.resize(n+1,1);
            for(int i = 0; i <=n;i++) par[i] = i;
        }
        int findParent(int node){
            if(node  == par[node]) return node;
            return par[node] = findParent(par[node]);
        }
        void unionBySize(int u , int v){
            int pu = findParent(u) , pv = findParent(v);
            if(pu == pv) return;
            if(size[pu] < size[pv]){
                par[pu] = pv;
                size[pv]+=size[pu];
            }else{
                par[pv] = pu;
                size[pu]+=size[pv];
            }
        }
};
class Solution {
public:
    
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        unordered_map<int,vector<int>> mp;
        for(int i = 0;i < n-1;i++){
            if(nums[i+1] - nums[i] <= maxDiff){
                mp[i].push_back(i+1);
                mp[i+1].push_back(i);
            }
        }
        DSU dsu(n);
        for(auto i : mp){
            int u = i.first;
            for(auto j : i.second) dsu.unionBySize(u,j);
        }
        vector<bool> ans;
        for(auto i : queries){
            if(dsu.findParent(i[0]) != dsu.findParent(i[1])){
                ans.push_back(false);
            }else ans.push_back(true);
        }
        return ans;
    }
};