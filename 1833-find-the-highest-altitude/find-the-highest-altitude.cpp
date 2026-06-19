class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans =0 , maxi  =0 ;
        for(int i=0;i < gain.size();i++){
            ans+=gain[i];
            maxi = max(ans,maxi);
        }
        return maxi;
    }
};