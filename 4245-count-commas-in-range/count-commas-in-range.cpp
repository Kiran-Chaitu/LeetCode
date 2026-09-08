class Solution {
public:
    int countCommas(int n) {
        int ans = n - 999;
        return ans > 0 ? ans : 0 ;
    }
};