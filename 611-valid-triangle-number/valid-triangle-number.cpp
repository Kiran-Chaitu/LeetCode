class Solution {
public:
    int triangleNumber(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size() , ans=0;
        for(int i=n-1;i>1;i--){
            int l=0,r = i-1 , k =arr[i];
            while(l<r){
                if(arr[l] + arr[r] > k){
                    ans+=(r-l);
                    r--;
                }
                else l++;
            }
        }
        return ans;
    }
};