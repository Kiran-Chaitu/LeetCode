class DisJointSetUnion{
    private:
        vector<int> parent,size;
    public:
        DisJointSetUnion(int n){
            parent.resize(n+1);
            size.resize(n+1,1);
            for(int i=0;i<=n;i++) parent[i] = i;
        }
        int findParent(int node){
            if(node == parent[node]) return node;
            return parent[node] = findParent(parent[node]);
        }
        void unionBySize(int u, int v){
            int pu = findParent(u) , pv = findParent(v);
            if(pu == pv) return;
            if(size[pu] > size[pv]){
                parent[pv] = pu;
                size[pu]+=size[pv];
            }else{
                parent[pu] = pv;
                size[pv]+=size[pu];
            }
        }
        int getSize(int node){
            return size[node];
        }
        int getLargestComponentSize(int n){
            int ans = 0;
            for(int i=0;i<=n;i++){
                if(parent[i] == i){
                    ans = max(ans, size[i]);
                }
            }
            return ans;
        }
};
class Solution {
public:
    bool isValid(int row , int col , int n){
        return row >=0 and row <  n and col >=0 and col < n;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisJointSetUnion dsu(n*n);
        vector<pair<int,int>> directions = {{-1,0} , {1,0} , {0,-1} , {0,1}};
        for(int i = 0; i < n ; i++){
            for(int j = 0; j < n;j++){
                if(grid[i][j]==0) continue;
                for(auto k : directions){
                    int r = i + k.first , c = j + k.second;
                    if(isValid(r,c,n) and grid[r][c]){
                        int node = i * n + j;
                        int adjNode = r * n + c;
                        dsu.unionBySize(node, adjNode);
                    }
                }
            }
        }
        int ans =dsu.getLargestComponentSize(n*n);
        for(int i=0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j]) continue;
                unordered_map<int,int> mp;
                for(auto k : directions){
                    int r = i + k.first , c = j + k.second;
                    if(isValid(r,c,n) and grid[r][c]){
                        int adjNode = r * n + c;
                        int par = dsu.findParent(adjNode);
                        mp[par] = dsu.getSize(par);
                        // cout<<par<<" "<<dsu.getSize(par)<<endl;
                    }
                }
                int sum = 0;
                for(auto k : mp){
                    sum+=k.second;
                }
                ans = max(ans,sum+1);
            }
        }
        return ans;
    }
};