class Solution {
public:
    void dfs(int node , vector<bool> &vis , unordered_map<int,vector<int>> &adj , int dest){
        if(vis[node]) return;
        if(node == dest){
            vis[node] = true;
            return;
        }
        vis[node] = true;
        for(auto i : adj[node]){
            dfs(i , vis , adj ,dest);
        }

    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<bool> vis(n , false);
        unordered_map<int, vector<int>> adjList;
        for(auto i : edges){
            adjList[i[0]].push_back(i[1]);
            adjList[i[1]].push_back(i[0]);
        }
        dfs(source , vis , adjList , destination);
        return vis[destination];
    }
};