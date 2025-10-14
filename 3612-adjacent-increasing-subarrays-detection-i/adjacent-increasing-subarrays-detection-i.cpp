class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& arr, int k) {
        int n=arr.size();
        for(int i=0;i<=n-2*k;i++){
            bool flag = true;
            int j=i;
            while(j<i+k-1){
                if(arr[j]>= arr[j+1]){
                    flag = false;
                    break;
                }
                j++;
            }
            if(flag){
                j=i+k;
                while(j<(i+2*k-1)){
                    if(arr[j] >= arr[j+1]){
                        flag = false;
                        break;
                    }
                    j++;
                }
                if(flag) return true;
            }
        }
        return false;
    }
};