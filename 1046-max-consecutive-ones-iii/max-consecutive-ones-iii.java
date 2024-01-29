class Solution {
    public int longestOnes(int[] nums, int k) {
     int i=0;
     int j=0;
     int n=nums.length;
     while(j<n){
         if(nums[j]==0){
             k--;
         }
         if(k<0){
             if(nums[i]==0){
                 k++;
             }
             i++;
         }
         j++;
        } 
        return j-i;  
    }
}