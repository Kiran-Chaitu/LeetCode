class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        unordered_map<string , int > mp;
        int n=arr.size(),x=1;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        for(int i=0;i<n;i++){
            if(mp[arr[i]]==1 and x<=k){
                if(x==k) return arr[i];
                x++;
            }
        }
        return "";
    }
};