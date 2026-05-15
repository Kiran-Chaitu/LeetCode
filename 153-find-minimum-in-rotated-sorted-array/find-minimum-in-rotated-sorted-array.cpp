class Solution {
public:
    int findMin(vector<int>& arr) {
        int ans=INT_MAX;
        int l=0,r=arr.size()-1;
        while(l <= r){
            int mid = (l+r) >> 1;
            if(arr[l] <= arr[r]){
                ans = min(ans, arr[l]);
                break;
            }
            if(arr[l]<=arr[mid]){
                ans = min(ans, arr[l]);
                l = mid + 1;
            }
            else{
                ans = min(ans, arr[mid]);
                r = mid -1;
            }
        }
        return ans;
    }
};