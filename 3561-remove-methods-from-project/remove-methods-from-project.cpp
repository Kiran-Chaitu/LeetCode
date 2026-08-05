// class DSU{
//     private:
//         vector<int> parent, size;
//     public:
//         DSU(int n){
//             parent.resize(n+1,0);
//             size.resize(n+1,1);
//             for(int i = 0;i<=n;i++) parent[i] = i;
//         }
//         int findParent(int node){
//             if(parent[node] == node) return node;
//             return parent[node] = findParent(parent[node]);
//         }
//         void unionBySize(int u, int v){
//             int pu = findParent(u) , pv = findParent(v);
//             if(pu == pv) return;
//             if(size[pu] <= size[pv]){
//                 parent[pu] = pv;
//                 size[pv] += size[pu];
//             }else{
//                 parent[pv] = pu;
//                 size[pu] += size[pv];
//             }
//         }
// };

class Solution {
public:

    
    void dfs(int node,unordered_map<int,vector<int>> &adj , vector<int> &vis , unordered_map<int,int> &sus){
        vis[node] = true;
        sus[node] = 1;
        for(auto i : adj[node]){
            if(!vis[i]) dfs(i, adj, vis,sus);
        }
    }

    void solver(int node,unordered_map<int,vector<int>> &adj , vector<int> &vis , vector<bool> &temp ,unordered_map<int,int> &sus ){
        vis[node] = true;
        for(auto i : adj[node]){
            if(!vis[i]) solver(i, adj, vis, temp , sus);
            else{
                if(sus.find(i)!=sus.end()){
                    temp[0] = true;
                    return;
                }
            }
        }
    }
   
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        unordered_map<int,vector<int>> adj;
        for(auto i:invocations){
            adj[i[0]].push_back(i[1]);
        }
        // DSU dsu(n);
        // for(auto i : adj){
        //     for(auto j : i.second) dsu.unionBySize(i.first , j);
        // }
        vector<int> vis(n ,0) ;
        unordered_map<int,int> sus;
        dfs(k , adj,vis, sus);
        vector<int> ans;
        // for(auto i : sus) cout<<i<<" ";
        // // cout<<endl;
        // for(int i = 0; i < n;i++){
        //     if(vis[i]) continue;
        //     for(auto j : sus){
        //         if(dsu.findParent(i) == dsu.findParent(j)){
        //             // cout<<i<<" "<<j<<endl;
        //             temp = false;
        //             break;
        //         }
        //     }
        // }


        vector<bool> temp = {false};
        for(int i = 0 ;i < n;i++){
            if(vis[i]) continue;
            solver(i, adj, vis, temp , sus);
            if(temp[0]) break;
        }

        if(temp[0]){
            for(int i = 0;i < n; i++) ans.push_back(i);
        }else{
            for(int i = 0; i < n ; i++){
                if(sus.find(i) == sus.end()) ans.push_back(i);
            }
        }
        return ans;
    }
};