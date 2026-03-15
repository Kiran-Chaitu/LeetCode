class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int , vector<pair<int,int>>> mp;
        for(auto i : flights){
            mp[i[0]].push_back({i[1] , i[2]});
        }
        vector<int> ans(n , 1e9);
        ans[src] = 0;
        queue<pair<int, pair<int,int>>> q;
        q.push({ 0  , {src , 0}});
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            int stops = temp.first , node = temp.second.first , pr = temp.second.second;
            if(stops >k) continue;
            for(auto i : mp[node]){
                int adjNode = i.first , adjPr = i.second;
                if(ans[adjNode] > pr + adjPr and stops <=k){
                    ans[adjNode] =pr + adjPr;
                    q.push({stops+1 , {adjNode , pr + adjPr}});
                }
            }
        }
        return ans[dst] != (int)(1e9) ? ans[dst] : -1;
    }
};