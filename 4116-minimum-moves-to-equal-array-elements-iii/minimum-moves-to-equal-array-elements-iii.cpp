class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi = INT_MIN;
        for(auto i : nums) maxi = max(maxi , i);
        int ans = 0;
        for(auto i : nums) ans += maxi - i;
        return ans;
    }
};