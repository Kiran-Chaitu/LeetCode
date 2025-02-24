class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> tmp;
        int n=nums.size();
        if(k>=n) k=k%n; 
        reverse(nums.begin() , nums.end() -k);
        reverse(nums.end() - k, nums.end());
        reverse(nums.begin() , nums.end());
    }
};