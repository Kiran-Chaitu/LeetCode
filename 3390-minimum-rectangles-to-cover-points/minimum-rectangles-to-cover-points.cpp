class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        sort(points.begin() , points.end());
        int it = points[0][0] + w;
        int c = 1 , n = points.size();
        for(int i = 0; i < n; i++){
            if(points[i][0] <= it) continue;
            it = points[i][0] + w;
            c++; 
        }
        return c;
    }
};