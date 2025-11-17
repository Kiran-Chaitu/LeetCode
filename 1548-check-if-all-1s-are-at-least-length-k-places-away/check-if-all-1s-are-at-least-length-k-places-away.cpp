class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int fi = 0;
        while(fi < nums.size() and nums[fi] == 0) fi++;
        for(int i = fi+1 ; i < nums.size();i++){
            if(nums[i]){
                if(i - fi -1 < k) return false;
                // cout<<i <<" "<<fi<<endl;
                fi = i;
            }
        }
        return true;
    }
};