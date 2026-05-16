class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin() , nums.end());
        int n = nums.size();
        set<vector<int>> st;
        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                int l = j+1 , r = n-1;
                long long sum = (long long)(target) - (long long)(nums[i]) - (long long)(nums[j]);
                while( l < r){
                    if(nums[l] + nums[r] == sum){
                        st.insert({nums[i] , nums[j] , nums[l] , nums[r]});
                        l++;
                        r--;
                    }else if(nums[l] + nums[r] < sum){
                        l++;
                    }else{
                        r--;
                    }
                }
            }
        }
        vector<vector<int>> temp;
        for(auto i:st) temp.push_back(i);
        return temp;
    }
};