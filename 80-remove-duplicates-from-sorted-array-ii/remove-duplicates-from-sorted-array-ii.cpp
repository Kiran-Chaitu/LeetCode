
#define ll long long
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==1) return 1;
        ll i =0 ,j=0 , n = nums.size();
        while(j<n-1 ){
            ll c=1;
            while(j<n-1 and  nums[j]==nums[j+1]){
                j++;
                c++;
            }
            if(c>=2){
                nums[i]= nums[j];
                nums[i+1] = nums[j];
                i+=2;
                j++;
            }
            else{
                nums[i++] = nums[j++];
            }
        }
        if(j<n and nums[j]!=nums[j-1]){
            nums[i++]= nums[j];
        }
        return i;
    }
};