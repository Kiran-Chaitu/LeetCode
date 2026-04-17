class DisJointSetUnion{
        private:
            vector<int> parent , size;
        public:
            DisJointSetUnion(int n){
                parent.resize(n);
                size.resize(n,1);
                for(int i=0;i<n;i++) parent[i] = i;
            }
            int findParent(int node){
                if(parent[node] == node) return node;
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
            int getUniqueParentCount(){
                int count =0;
                for(int i = 0; i < parent.size();i++){
                    if(findParent(i) == i) count++;
                }
                return count;
            }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisJointSetUnion dsu(n);
        for(auto i : connections){
            dsu.unionBySize(i[0] , i[1]);
        }
        int e = connections.size();
        if( e < n-1) return -1;
        int components = dsu.getUniqueParentCount();
        return components-1;
        
    }
};