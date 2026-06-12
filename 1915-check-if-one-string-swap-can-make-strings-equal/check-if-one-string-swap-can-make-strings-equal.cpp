class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<int> temp;
        int n = s1.size();
        for(int i = 0;i<n;i++){
            if(s1[i]!=s2[i]) temp.push_back(i);
        }
        if(temp.empty()) return true;
        if(temp.size() == 1 || temp.size() > 2) return false;
        char ch = s1[temp[0]];
        s1[temp[0]]  = s1[temp[1]];
        s1[temp[1]] = ch;
        return s1 == s2;
    }
};