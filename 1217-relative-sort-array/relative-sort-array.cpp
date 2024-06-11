class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int> mp;
        for(int i=0;i<arr1.size();i++) mp[arr1[i]]++;
        int j=0;
        for(int i=0;i<arr2.size();i++){
            while(mp[arr2[i]]!=0){
                arr1[j++]=arr2[i];
                mp[arr2[i]]--;
            }
            mp.erase(arr2[i]);
        }
        vector<int> v;
        for(auto i : mp){
            int k=i.second;
            while(k--)  v.push_back(i.first);
        }
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++) arr1[j++]=v[i];
        return arr1;
    }
};