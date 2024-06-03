class Solution {
public:
    int appendCharacters(string s, string t) {
        int i=0,j=0,ls=0,temp=0;
        while(i<s.size() and j<t.size()){
            if(s[i]==t[j]){
                i++;
                j++;
                temp++;
            }
            else{
                i++;
            }
            ls = max(ls,temp);
        }
        return t.size() - ls;
    }
};