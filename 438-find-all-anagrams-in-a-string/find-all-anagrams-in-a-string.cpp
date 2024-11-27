class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        sort(p.begin(),p.end());
        int n=s.size(),m=p.size();
        vector<int> ans;
        unordered_map<char,int> mp1,mp2;
        for(int i=0;i<m;i++){
            mp1[p[i]]++;
            mp2[s[i]]++;
        }
        
        for(int i=0;i<=n-m;i++){
            if(mp1==mp2) ans.push_back(i);
            mp2[s[i]]--;
            if(mp2[s[i]] <=0) mp2.erase(s[i]);
            mp2[s[i+m]]++;
        }
        return ans;
    }
};