class Solution {
public:
    bool dfs(int node ,vector<bool> &vis , vector<bool> &path,  unordered_map<int,vector<int>> &adj){
        vis[node]=true;
        path[node] = true;
        for(auto i : adj[node]){
            if(!vis[i]){
                if(dfs(i , vis, path, adj)) return true;
            }
            else{
                if(path[i]) return true;
            }
        }
        path[node] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> mp;
        for(auto i : prerequisites){
            mp[i[0]].push_back(i[1]);
        }
        vector<bool> vis(numCourses+1 , false) , path(numCourses+1 , false);
        for(int i =1 ;i <=numCourses ;i++){
            if(!vis[i]){
                if(dfs(i , vis , path , mp)){
                    return false;
                }
            }
        }
        return true;
    }
};