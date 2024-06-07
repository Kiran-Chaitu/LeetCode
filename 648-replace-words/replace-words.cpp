class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_map<string,int> mp;
        for(int i=0;i<dictionary.size();i++){
            mp[dictionary[i]]=1;
        }
        string s="",ans="";
        for(int i=0;i<sentence.size();i++){
            s+=sentence[i];
            if(mp.find(s)!=mp.end()){
                ans+=s;
                int j;
                for(j=i;j<sentence.size();j++){
                    if(sentence[j]==' ') break;
                }
                i=j-1;
                s="";
            }
            if(s.size()>0 and s[s.size()-1]==' '){
                ans+=s;
                s="";
            }
        }
        if(s.size()>0) ans+=s;
        return ans;
    }
};