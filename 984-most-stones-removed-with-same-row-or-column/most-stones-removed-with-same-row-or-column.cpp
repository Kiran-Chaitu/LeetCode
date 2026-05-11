class DisJointSetUnion{
    private:
     vector<int> parent, size;
    public:
        vector<bool> stones;
        DisJointSetUnion(int n){
            // cout<<"MAX "<<n<<endl;
            parent.resize(n+1);
            stones.resize(n+1);
            size.resize(n+1,1);
            for(int i=0;i<=n;i++){
                parent[i] = i;
            }
        }
        int findParent(int node){
            // cout<<node<<endl;
            if(node == parent[node]) return node;
            return parent[node] = findParent(parent[node]);
        }
        void unionBySize(int u , int v){
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
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxRow = 0 , maxCol = 0;
        for(auto i : stones){
            maxRow  = max(maxRow, i[0]);
            maxCol = max(maxCol, i[1]);
        }
        unordered_map<int,int> stoneNode;
        DisJointSetUnion dsu(maxRow + maxCol+1);
        for(auto i : stones){
            int rowNode = i[0];
            int colNode = maxRow + i[1]+1;
            dsu.unionBySize(rowNode , colNode);
            stoneNode[rowNode] = 1;
            stoneNode[colNode] = 1;
        }
        int c=0;
        for(auto i : stoneNode){
            if(dsu.findParent(i.first) == i.first) c++;
        }
        return stones.size() - c;
    }
};