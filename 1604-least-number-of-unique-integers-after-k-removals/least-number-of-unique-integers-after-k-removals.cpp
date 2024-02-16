bool compare(pair<int,int> a,pair<int,int> b){
    return a.second>b.second;
}
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n=arr.size();
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            m[arr[i]]++;
        }
        vector<pair<int,int>> frArr(m.begin(),m.end());
        sort(frArr.begin(),frArr.end(),compare);
        vector<int> ans;
        for(auto i : frArr){
            for(int j=0;j<i.second;j++){
                ans.push_back(i.first);
            }
        }
        m.clear();
        for(int i=0;i<n-k;i++) m[ans[i]]++;
        return m.size();
    }
};