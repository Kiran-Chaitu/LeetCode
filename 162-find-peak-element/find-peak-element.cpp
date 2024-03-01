class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int n=arr.size(),l=1,r=n-2;
        if(n==1) return 0;
        if(arr[0]>arr[1]) return 0;
        if(arr[n-1] > arr[n-2]) return n-1;
        while( l<=r ){
            int mid=(l+r)>>1;
            if( arr[mid] > arr[mid-1] and arr[mid] > arr[mid +1]) return mid;
            if( arr[mid] > arr[mid-1]) l=mid+1;
            else r=mid-1;
        }
        return -1;
    }
};