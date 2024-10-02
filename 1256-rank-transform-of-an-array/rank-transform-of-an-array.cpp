class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int,int> mp;
        int k=1;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]] = k;
        }
        for(auto i:mp){
            mp[i.first] = k;
            k++;
        }
        vector<int> v;
        for(int i=0;i<arr.size();i++){
            v.push_back(mp[arr[i]]);
        }
        return v;
    }
};