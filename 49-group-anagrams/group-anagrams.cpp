class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> t=strs;
        unordered_map<string,vector<int>> m;
        if(strs.size()==0) return {{""}};
        else if(strs.size()==1) return {{strs[0]}};
        vector<vector<string>> ans;
        for(int i=0;i<strs.size();i++){
            sort(strs[i].begin(),strs[i].end());
        }
        for(int i=0;i<strs.size();i++){
            m[strs[i]].push_back(i);
        }
        for(auto i: m){
            vector<string> x;
            for(int j=0;j<m[i.first].size();j++){
                x.push_back(t[i.second[j]]);
            }
            ans.push_back(x);
        }
        return ans;
    }
};