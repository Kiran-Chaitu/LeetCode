class Solution {
public:
    string reverse(string s){
        int n = s.size()-1,i=0;
        while(i<n){
            char t = s[i];
            s[i++] = s[n];
            s[n--] = t;
        }
        return s;
    }
    string invert(string s){
        for(int i=0;i<s.size();i++){ 
            if(s[i]=='1') s[i]='0'; else s[i]='1';
        }
        return s;
    }
    char findKthBit(int n, int k) {
        n--;
        string s="0";
        while(n--){
            s = s + "1" + reverse(invert(s));
        }
        return s[k-1];
    }
};