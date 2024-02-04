class Solution {
public:
    string reverseWords(string s) {
        string ns;
        int j=s.size()-1,i;
        while(s[j]==' ')    j--;
        while(j>=0){
            while(j>=0 and(s[j]!=' ')){
                j--;
                if(j<0) break;
            }
            i=j+1;
            while(i<s.size() and (s[i]!=' ')){
                ns+=s[i];
                i++;
                
            }
            if(j>=0) ns+=' ';
            while(j>=0 and (s[j]==' ')) j--;
        
        }
        if(!ns.empty() and ns.back()==' ') ns.pop_back();
        return ns;
    }
};