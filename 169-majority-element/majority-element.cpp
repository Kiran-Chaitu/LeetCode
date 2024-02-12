class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int c=0,can;
        for(int num:nums){
            if(c==0){
                can=num;
                c++;
            }
            else if(can==num)
                c++;
            else c--;
        }
        return can;
    }
    
};