class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        sort(nums.begin(),nums.end());
        return nums;
    }
};