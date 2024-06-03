class Solution {
public:
    int appendCharacters(string s, string t) {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        int i=0,j=0,temp=0;
        while(i<s.size() and j<t.size()){
            if(s[i]==t[j]){
                i++;
                j++;
                temp++;
            }
            else    i++;
        }
        return t.size() - temp;
    }
};