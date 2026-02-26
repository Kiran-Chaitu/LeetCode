class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size() , m = heights[0].size();
        vector<vector<int>> ans(n , vector<int>(m , 1e9));
        vector<vector<int>> dir = {{-1,0} , {0 , -1} , {0 , 1} , {1 , 0}};
        priority_queue<vector<int> , vector<vector<int>> ,greater<vector<int>>> pq;
        ans[0][0] =  0 ;
        pq.push({0,0,0});
        while(!pq.empty()){
            auto node = pq.top();
            int d = node[0] , i = node[1] , j = node[2];
            pq.pop();
            if(d > ans[i][j]) continue;
            if(i == n-1 and j == m-1) return d;
            for(auto k : dir){
                int nr = i + k[0] , nc = j + k[1];
                if(nr >=0 and nr<n and nc >=0 and nc < m){
                    int diff = abs(heights[i][j] - heights[nr][nc]);
                    int maxi =  max(diff,d);
                    
                    if(ans[nr][nc] > maxi){
                        // cout<<maxi<<" "<<diff<<" "<<nr<<" "<<nc<<" "<<ans[nr][nc]<<endl;
                        ans[nr][nc] = maxi; 
                        pq.push({ans[nr][nc] , nr,nc});
                    }
                }
            }
            
        }
        return 0;
    }
};