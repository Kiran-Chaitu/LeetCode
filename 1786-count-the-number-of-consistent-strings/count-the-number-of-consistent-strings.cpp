class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        unordered_map<char,int> mp;
        for(int i=0;i<allowed.size();i++){
            mp[allowed[i]]++;
        }
        int count = 0;
        for(int i=0;i<words.size();i++){
            int c=0;
            for(int j=0;j<words[i].size();j++){
                if(mp[words[i][j]] > 0) c++;
            }
            if(c==words[i].size()) count++;
        }
        return count;

    }
};