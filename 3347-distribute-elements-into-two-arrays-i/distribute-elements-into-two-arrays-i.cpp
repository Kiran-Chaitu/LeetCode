class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> first , second;
        first.push_back(nums[0]);
        second.push_back(nums[1]);
        int n = nums.size();
        for(int i = 2; i < n; i++ ){
            if(first.back() > second.back()){
                first.push_back(nums[i]);
            }else{
                second.push_back(nums[i]);
            }
        }
        for(auto i : second) first.push_back(i);
        return first;
    }
};