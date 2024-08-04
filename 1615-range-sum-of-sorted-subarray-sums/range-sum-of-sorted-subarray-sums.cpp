class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<long long int> subSums;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                long long int sum=0;
                for(int k=i;k<=j;k++){ 
                    sum+=nums[k];
                    //cout<<nums[k]<<" "<<sum<<endl;
                }
                subSums.push_back(sum);
            }
        }
        long long int sum=0;
        sort(subSums.begin(),subSums.end());
        for(int i=left-1;i<=right-1;i++){
            sum+=subSums[i]%1000000007;
            //cout<<sum<<" "<<subSums[i]<<endl;
        }
        return sum%1000000007;
    }
};