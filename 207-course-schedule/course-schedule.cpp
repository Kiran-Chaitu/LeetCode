class Solution {
public:
    bool dfs(unordered_map<int,vector<int>> &mp, vector<int> &vis , vector<int> &pathVis , int val){
        if(vis[val]){
            if(pathVis[val]) return true;
            return false;
        }
        vis[val] = 1;
        pathVis[val] = 1;
        bool temp = false;
        for(auto i : mp[val]){
            temp |= dfs(mp , vis,pathVis , i);
        }
        pathVis[val] =0;
        return temp;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> mp;
        vector<int> vis(numCourses) , pathVis(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            mp[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for(int i =0 ; i  < numCourses ; i++){
            if(!vis[i]){
                if(dfs(mp , vis , pathVis , i)) return false;
            }
        }
        return true;
    }
};