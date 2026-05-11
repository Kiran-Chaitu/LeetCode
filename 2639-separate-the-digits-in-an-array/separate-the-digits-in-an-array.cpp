class Solution {
public:
    vector<int> helper(int n){
        vector<int> arr;
        while(n > 0){
            int rm = n%10;
            arr.push_back(rm);
            n/=10;
        }
        return arr;
    }
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(auto i : nums){
            vector<int> temp = helper(i);
            for(int j = temp.size()-1;j>=0;j--){
                ans.push_back(temp[j]);
            }
        }
        return ans;
    }
};