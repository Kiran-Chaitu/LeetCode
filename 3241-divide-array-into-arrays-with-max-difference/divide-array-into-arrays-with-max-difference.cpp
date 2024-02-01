class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> v;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i+=3){
            if(nums[i+2] - nums[i] <= k){
                vector<int> t;
                for(int j=i;j<i+3;j++){
                    t.push_back(nums[j]);
                }
                v.push_back(t);
            }
            else return {};
        }
        return v;
    }
};