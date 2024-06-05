class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        map<char,vector<int>> mp;
        for(int i=0;i<words.size();i++){
            unordered_map<char,int> dum;
            for(int j=0;j<words[i].size();j++){
                dum[words[i][j]]++;
            }
            for(auto k:dum){
                    mp[k.first].push_back( k.second);
            }
        }
        vector<string> v;
        for(auto i : mp){
            if(i.second.size() == words.size()){
                sort(i.second.begin(),i.second.end());
                string dum="";
                dum+=i.first;
                for(int j=0;j<i.second[0];j++) v.push_back(dum);
            }
        }
        return v;
    }
};