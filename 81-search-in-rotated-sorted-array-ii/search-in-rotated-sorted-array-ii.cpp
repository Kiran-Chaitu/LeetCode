class Solution {
public:
    bool search(vector<int>& arr, int k) {
        int l=0,r=arr.size()-1,mid;
    while(l<=r){
        mid=(l+r)>>1;
        if(arr[mid]==k) return 1;
        if(arr[l]==arr[mid] and arr[r]==arr[mid]){
            l++;
            r--;
        } 
        else if(arr[l]<=arr[mid]){
            if(arr[l]<=k and arr[mid]>k) r=mid-1;
            else l=mid+1;
        }
        else{
            if(arr[mid]<k and arr[r]>=k) l=mid+1;
            else r=mid-1;
        }
    }  
    return 0;
    }
};