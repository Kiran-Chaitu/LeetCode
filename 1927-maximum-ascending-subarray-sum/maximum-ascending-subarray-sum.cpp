class Solution {
public:
    int maxAscendingSum(vector<int>& arr) {
        long long sum  = arr[0] , maxi =arr[0] , n  = arr.size();
        if(n==1) return arr[0];
        for(int i=1;i<n;i++){
            if(arr[i] <= arr[i-1]){
                sum = arr[i];
            }
            else sum+=arr[i];
            maxi = max(maxi,sum);
        }
        return maxi;
    }
};