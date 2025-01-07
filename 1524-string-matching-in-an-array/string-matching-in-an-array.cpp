class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        for(auto i:words){
            for(int j=0;j<words.size();j++){
                if( i == words[j]) continue;
                if(words[j].find(i)!=string::npos){
                    ans.push_back(i);
                    break;
                }
            }
        }
        return ans;
    }
};