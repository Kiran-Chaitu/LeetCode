class Solution {
  void sortColors(List<int> nums) {
     int c=0,c1=0,c2=0;
     for(int i=0;i<nums.length;i++){
        if(nums[i]==0) c++;
        else if(nums[i]==1) c1++;
        else c2++;
     }
     int k=0;
     while(c!=0){
        nums[k++]=0;
        c--;
     }
     while(c1!=0){
        nums[k++]=1;
        c1--;
     } 
     while(c2!=0){
        nums[k++]=2;
        c2--;
     } 
  }
}