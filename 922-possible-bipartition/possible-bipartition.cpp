class Solution {
public:
    bool dfs(int node,int col, vector<int> &color , unordered_map<int,vector<int>> &adj){
        color[node] = col;
        for(auto i : adj[node]){
            if(color[i] == -1){
                if(dfs(i , !col , color, adj) == false) return false;
            }else if(color[i] == col){
                return false;
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int,vector<int>> adj;
        for(auto i : dislikes){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int> color(n+1 , -1);
        for(int i=1;i<=n;i++){
            if(color[i]==-1){
                if(dfs(i ,0 , color , adj) == false) return false;
            }
        }
        return true;
    }
};