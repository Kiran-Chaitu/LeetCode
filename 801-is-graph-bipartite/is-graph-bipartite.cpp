class Solution {
public:
    void dfs(unordered_map<int,vector<int>> &mp , vector<int> &vis , bool col , int i , bool &ans){
        if(!ans) return;
        if(vis[i]!=-1){
            if(vis[i]!=col){
                ans = false;
                return;
            }
            return;
        }
        vis[i] = col;
        for(auto k : mp[i]){
            dfs(mp , vis , !col , k ,ans);
            if(!ans) return;
        }
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n  = graph.size() ;
        vector<int> vis(n,-1);
        unordered_map<int,vector<int>> mp;
        for(int i =0;i<n;i++){
            mp[i] = graph[i];
        }
        bool ans = true;
        for(int i = 0 ;i < n ;i++){
            if(vis[i]==-1) dfs(mp,vis , false,i,ans);
            if(!ans) break;
        }
        return ans;
    }
};