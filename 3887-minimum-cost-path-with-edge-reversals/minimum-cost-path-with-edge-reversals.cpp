class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<int> dist( n , 1e9);
        vector<bool> sch(n, false);
        // sch[0]=true;
        unordered_map<int , vector<pair<int,int>>> out , in;
        for(auto i : edges){
            in[i[1]].push_back({i[0] , 2 * i[2]});
            out[i[0]].push_back({i[1] , i[2]});
        }
        dist[0] = 0;
        priority_queue<pair<int,int>  , vector<pair<int,int>>  , greater<pair<int,int>>> pq;
        pq.push({dist[0] , 0});
        while(!pq.empty()){
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(d > dist[node]) continue;
            for(auto i :out[node] ){
                int nxt = i.first;
                if(d + i.second < dist[nxt]){
                    dist[nxt] = d + i.second;
                    pq.push({d + i.second , nxt});
                }
            }
            if(!sch[node]){
                for(auto i : in[node]){
                    int nxt = i.first;
                    if(d + i.second < dist[nxt]){
                        dist[nxt] = d + i.second;
                        pq.push({d + i.second , nxt});
                    }
                }
                sch[node] = true;
            }
        }
        return (dist[n-1] == (1e9)) ? -1 : dist[n-1];
    }
};