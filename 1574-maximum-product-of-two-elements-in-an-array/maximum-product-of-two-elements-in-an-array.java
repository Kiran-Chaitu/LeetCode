class Solution {
    public int maxProduct(int[] nums) {
        int firstMax = -1 , secondMax = -1 , n = nums.length;
        for(int i = 0;i < n ;i++ ){
            if(nums[i] >= firstMax){
                secondMax = firstMax;
                firstMax = nums[i];
            }else if(nums[i] > secondMax){
                secondMax = nums[i];
            }
        }
        return (firstMax-1) * (secondMax-1);
    }
}