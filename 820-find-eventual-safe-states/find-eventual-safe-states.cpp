class Solution {
public:
    bool dfs(unordered_map<int,vector<int>> &mp , unordered_map<int,int> &terms , vector<int> &vis , vector<int> &reach ,  int val){
        if(vis[val]){
            if(reach[val]) return true;
            return false;
        }
        vis[val] = 1;
        if(terms.find(val)!=terms.end()){ 
            reach[val] = 1;
            return true;
        }
        bool ans = true;
        for(auto i : mp[val]){
            ans &= dfs(mp , terms,  vis , reach , i);
        }
        reach[val] = ans;
        return reach[val];
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        unordered_map<int,vector<int>> mp;
        int n = graph.size();
        unordered_map<int,int> terms;
        vector<int> ans , vis(n) , reach(n);
        for(int i = 0 ; i<n;i++){
            mp[i] = graph[i];
            if(graph[i].size()==0) terms[i] = 1;
        }
        for(int i = 0 ; i <n;i++){
            if(!vis[i]){
                dfs(mp , terms , vis , reach , i);
            }
        }
        for(int i =0 ; i < n ; i++) if(reach[i]) ans.push_back(i);
        return ans;
    }
};