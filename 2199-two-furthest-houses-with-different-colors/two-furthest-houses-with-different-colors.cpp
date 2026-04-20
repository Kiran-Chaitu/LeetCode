class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int color = colors[0] ;
        int n = colors.size() , i = n-1 , j =0 , col = colors[n-1];
        while(i >0  and colors[i]==color){
            i--;
        }
        while(j < n and colors[j]==col){
            j++;
        }
        return max(i , n - j-1);
    }
};