class Solution {
public:
    void dfs(int i , unordered_map<int,vector<int>> &mp , vector<bool> &vis){
        if(vis[i] || mp.find(i)==mp.end()) return;
        cout<<i<<" ";
        vis[i] = true;
        for(auto j : mp[i]){
            dfs(j , mp , vis);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<n;i++){
            for(int j = 0 ;j<n;j++){
                if(i!=j and isConnected[i][j]){
                    mp[i].push_back(j);
                }
            }
        }
        // for(auto i : mp){
        //     cout<<i.first<<" -> ";
        //     for(auto j : i.second) cout<<j<<" ";
        //     cout<<endl;
        // }
        // if(mp.size() == 0) return isConnected.size();
        vector<bool> vis(n,false);
        int ans =0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                cout<<"i = "<<i<<endl;
                if(mp[i].size() > 0) dfs( i , mp , vis );
                else vis[i] = true;
                ans++;
            }
        }
        return ans;
    }
};