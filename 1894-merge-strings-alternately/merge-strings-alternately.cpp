class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans="";
        if(word1.size()==word2.size()){
            
            for(int i=0;i<word1.size();i++){
                ans+=word1[i];
                ans+=word2[i];
            }
            return ans;
        }
        else{
            int l=max(word1.size(),word2.size());
            int i=0,j=0;
            for(int k=0;k<l;k++){
                if(i==word1.size()){
                    ans+=word2[j++];
                }
                else if(j==word2.size()){
                    ans+=word1[i++];
                }
                else{
                    ans+=word1[i++];
                    ans+=word2[j++];
                }

            }
        }
        return ans;
    }
};