class Solution {
public:
    void dfs(vector<vector<int>>& image , int i , int j ,int n , int m, int col , int color , vector<vector<int>>& vis){
        if(i < 0 || i >= n || j <0 || j>=m || vis[i][j]) return;
        if(image[i][j]!= col) return;
        image[i][j] = color;
        vis[i][j] = 1;
        dfs(image , i+1 ,j , n , m , col , color , vis);
        dfs(image , i-1 ,j , n , m , col , color , vis);
        dfs(image , i ,j+1 , n , m , col , color  , vis);
        dfs(image , i ,j-1 , n , m , col , color , vis);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int col = image[sr][sc];
        if(col == color) return image;
        int n= image.size() , m = image[0].size();
        vector<vector<int>> vis(n , vector<int>(m));
        dfs(image , sr , sc , n , m, col , color , vis);
        return image;
    }
};