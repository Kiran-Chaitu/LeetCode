class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        vector<long long int> subSums;
        for(int i=0;i<n;i++){
            long long int sum=0;
            for(int j=i;j<n;j++){ 
                sum+=nums[j];
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