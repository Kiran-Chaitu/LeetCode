class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxa = INT_MIN;
        int i = 0,j = height.size() - 1;
        while(i < j){
            int l = min( height[i], height[j]);
            int b = j - i;
            int area = l * b;
            maxa = max( maxa, area);
            if( height[i] < height[j]) i++;
            else j--;
        }
        return maxa;
    }
};