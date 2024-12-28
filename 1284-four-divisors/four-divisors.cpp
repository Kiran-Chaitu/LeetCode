class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        long long int c=0;
        for(int i =0;i<nums.size();i++){
            if(nums[i]<6) continue;
            long long int fc=0,sq=sqrt(nums[i]),sum=0,j;
            for(j=2;j<=sq;j++){
                if((nums[i]%j==0)){
                    //cout<<j<<" "<<(nums[i]/j);
                    fc+=2;
                    sum+=(j+nums[i]/j);
                }
            }
            if(j-1==sqrt(nums[i])) fc--;
            if(fc==2){
                c+=(sum+1+nums[i]);
            }
            cout<<endl;
        }
        return c;
    }
};