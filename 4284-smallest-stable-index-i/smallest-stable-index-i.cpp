class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int maxi = INT_MIN , mini = INT_MAX , n = nums.size();
        vector<int> lg(n) , sm(n);
        for(int i = 0;i < n; i++){
            maxi = max(maxi , nums[i]);
            lg[i] = maxi;
        }
        for(int i=n-1;i>=0;i--){
            mini = min(mini , nums[i]);
            sm[i] = mini;
        }
        for(int i = 0;i < n;i++){
            int temp = lg[i] - sm[i];
            if(temp <= k) return i;
        }
        return -1;
    }
};