//typedef long long int lli;
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> v;
        int n=potions.size();
        sort(potions.begin(),potions.end());
        for(int i=0;i<spells.size();i++){
            long long int  l=0,r=n-1,mid,ans;
            while(l<=r){
                mid=(l+r)>>1;
                ans =(long long)spells[i] * (long long)potions[mid];
                if(ans >= success) r=mid-1;
                else l=mid+1;
            }
            v.push_back(n-l);
        }
        return v;
    }
};