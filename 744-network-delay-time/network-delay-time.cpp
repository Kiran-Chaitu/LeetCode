class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> ans( n+1 , INT_MAX);
        unordered_map<int,vector<pair<int,int>>> mp;
        for(auto i : times){
            mp[i[0]].push_back({i[1] , i[2]});
        }
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
        ans[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            auto it =pq.top();
            pq.pop();
            int dist = it.first , node = it.second;
            for(auto i : mp[node]){
                int adjNode = i.first , wt = i.second;
                if(ans[adjNode] > dist + wt){
                    ans[adjNode] = dist + wt;
                    pq.push({dist + wt , adjNode});
                }
            }
            
        }
        int maxi =-1;
        for(int i = 1; i<=n;i++){
            if(ans[i]==INT_MAX) return -1;
            if(ans[i] > maxi) maxi = ans[i];
        }
        return maxi;
    }
};