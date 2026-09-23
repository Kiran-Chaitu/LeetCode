class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = 0;
        int n = height.size() , i = 0 , j = n -1;
        while(i < j){
            int width  = j - i;
            int length = min(height[j] , height[i]);
            if(height[j] > height[i]) i++;
            else j--;
            area = max( area , width * length);
        }
        return area;
    }
};