class Solution {
public:
    vector <int> org,sh;
    Solution(vector<int>& nums) {
        org=nums;
        sh=nums;
    }
    
    vector<int> reset(){
        return org;
    }
    
    vector<int> shuffle(){
        next_permutation(sh.begin(),sh.end());
        return sh;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */