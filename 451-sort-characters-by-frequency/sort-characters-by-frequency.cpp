#include<bits/stdc++.h>
 bool compare(pair<char,int> a, pair<char,int> b){
    return a.second > b.second;
}
class Solution {
public:
    string customSort(string s){
        unordered_map<char, int> m;
        for (int i = 0; i < s.size(); i++) m[s[i]]++;
        vector<pair<char,int>> ans(m.begin(), m.end());
        sort(ans.begin(), ans.end(), compare);
        
        string res="";
        for(auto i:ans){
            res+=string(i.second,i.first);
        }
        return res;
    }
    string frequencySort(string s) {
        return customSort(s);
    }
};