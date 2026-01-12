class Solution {
public:
    
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans =0  , n =  points.size();
        for(int i =0 ; i < n-1 ; i++){
            int x = points[i][0] , y = points[i][1] , tarx = points[i+1][0] , tary = points[i+1][1];
            int tempx = 0 , tempy =0 , a = 0 , b = 0;
            tempx = abs(tarx - x) ;
            tempy = abs(tary - y);
            ans+=max(tempx,tempy);
        }
        return ans;
    }
};