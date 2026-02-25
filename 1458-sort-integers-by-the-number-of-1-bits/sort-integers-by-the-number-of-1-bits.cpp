class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> ans;
        sort(arr.begin() , arr.end());
        map<int , vector<int>> mp;
        for(auto i : arr){
            int c =0  , j=i;
            while(i> 0){
                if(i&1) c++;
                i>>=1;
            }
            mp[c].push_back(j);
        }
        for(auto i : mp){
            for(auto j : i.second) ans.push_back(j);
        }
        return ans;
    }
};