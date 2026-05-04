class DisJointSet{
    private:
        vector<int> parent,size;
    public:
        DisJointSet(int n){
            parent.resize(n+1);
            size.resize(n+1);
            for(int i=0;i<=n;i++) parent[i] = i;
        }
        int findParent(int node){
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisJointSet dsu(n);
        unordered_map<string, int> mp;
        for(int i = 0; i < n;i++){
            for(int j =1 ;j < accounts[i].size();j++){
                if(mp.find(accounts[i][j])!=mp.end()){
                    dsu.unionBySize(i , mp[accounts[i][j]]);
                }
                else{
                    mp[accounts[i][j]] = i;
                }
            }
        }
        map<int, set<string>> temp;
        for(auto i : mp){
            string mail = i.first ;
            int par = dsu.findParent(i.second);
            temp[par].insert(mail);
        }
        vector<vector<string>> ans;
        for(auto i:temp){
            vector<string> mails;
            mails.push_back(accounts[i.first][0]);
            for(auto j : i.second) mails.push_back(j);
            ans.push_back(mails);
        }
        return ans;
    }
};