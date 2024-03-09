class Solution {
public:
    bool bs(int t,vector<int> &v){
        int l=0,r=v.size()-1,mid;
        while(l<=r){
            mid=(l+r)>>1;
            if(v[mid]==t) return 1;
            else if(v[mid]>t) r=mid-1;
            else l=mid+1;
        }
        return 0;
    }
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        ios_base::sync_with_stdio(0);
        int n1 = nums1.size(), n2 =nums2.size();
        if(n1>=n2){
            for(int i=0;i<n2;i++){
                if(bs(nums2[i] , nums1)) return nums2[i];
            }
        }
        else{
            for(int i=0;i<n1;i++){
                if(bs(nums1[i] , nums2) ) return nums1[i];
            }
        }
        return -1;
    }
};