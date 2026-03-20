class Solution {
public:
    void dfs(unordered_map<int,vector<int>> &mp , int node ,vector<bool> &vis, bool &ans , int dest){
        if(vis[node]) return;
        vis[node] = true;
        if(node == dest){
            ans = true;
            return;
        }
        for(auto i : mp[node]){
            if(!vis[i]){
                dfs(mp , i ,vis, ans,dest);
            }
        }
    } 
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,vector<int>> mp;
        for(auto i : edges){
            mp[i[0]].push_back(i[1]);
            mp[i[1]].push_back(i[0]);
        }
        bool ans = false;
        vector<bool> vis(n,false);
        dfs(mp , source , vis, ans , destination);
        return ans;
    }
};