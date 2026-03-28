#define ll long long
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<ll,vector<pair<ll,ll>>> mp;
        for(auto i : roads){
            mp[i[0]].push_back({i[1] , i[2]});
            mp[i[1]].push_back({i[0] , i[2]});
        }
        // for(auto i : mp){
        //     cout<<i.first<<" :- ";
        //     for(auto j : i.second){
        //         cout<<"{"<<j.first<<":"<<j.second<<"} ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
        // cout<<endl;

        ll mod = (ll)(1e9 + 7) ;
        vector<ll> ways(n , 0) , ans(n , LLONG_MAX);
        ways[0]=1 , ans[0]=0;
        priority_queue<pair<ll,ll> , vector<pair<ll,ll>> , greater<pair<ll,ll>>> pq;
        pq.push({0 ,0});
        while(!pq.empty()){
            auto temp = pq.top();
            pq.pop();
            ll dist = temp.first , node = temp.second;
            // cout<<dist<<" "<<node<<endl;
            // cout<<"---------------"<<endl;
            for(auto  i : mp[node]){
                ll ng = i.first , wt = i.second;
                // cout<<ng<<" "<<wt<<endl;
                if(ans[ng] > dist + wt){
                    ways[ng] = (ways[node]);
                    ans[ng] = dist + wt;
                    pq.push({dist + wt,ng});
                }else if(ans[ng] == dist + wt){
                    ways[ng] = ((ways[ng])  +(ways[node]))%mod;
                }
            }
            // cout<<endl;
        }
        // for(auto i : ways) cout<<i<<" ";
        return ways[n-1]%mod;
    }
};