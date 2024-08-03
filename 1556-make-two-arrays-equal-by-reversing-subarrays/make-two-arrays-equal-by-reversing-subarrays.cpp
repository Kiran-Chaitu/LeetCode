class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        unordered_map<int,int> mp;
        for(int i=0;i<target.size();i++){
            mp[target[i]]++;
        }
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]--;
            if(mp[arr[i]]==0) mp.erase(arr[i]);
        }
        return mp.size()==0 ? true : false;
    }
};