class Solution {
public:
    int time = 0;
    void dfs(int node, int parent,unordered_map<int,vector<int>> &mp, vector<int> &low, vector<int> &tin, vector<int> &vis, vector<vector<int>> &bridges){
        vis[node] = 1;
        low[node] = time;
        tin[node] = time;
        time++;
        for(auto i : mp[node]){
            if(i == parent) continue;
            if(vis[i] == 1){
                low[node] = min(low[node] , low[i]);
            }else{
                dfs(i,node,mp,low,tin,vis,bridges);
                low[node] = min(low[node] , low[i]);
                if(low[i] > tin[node]){
                    bridges.push_back({node,i});
                }
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> low(n) , vis(n) , tin(n);
        unordered_map<int,vector<int>> mp;
        for(auto i:connections){
            mp[i[0]].push_back(i[1]);
            mp[i[1]].push_back(i[0]);
        }
        vector<vector<int>> bridges;
        dfs(0,-1,mp,low,tin,vis,bridges);
        return bridges; 
    }
};