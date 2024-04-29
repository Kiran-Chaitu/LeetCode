class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int x=0;
        for(int i=0;i<nums.size();i++){
            x^=nums[i];
        }
        int num=x^k;
        int c=0;
        while(num>0){
            if(num&1) c++;
            num=num>>1;
        }
        return c;
    }
};