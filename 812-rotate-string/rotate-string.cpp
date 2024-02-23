class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()) return false;
        int n=s.size(),i=0;
        while(i<n){
            string ns="";
            ns+=s[n-1];
            s.pop_back();
            s.insert(0,ns);
            if(s==goal) return true;
            i++;
        }
        return false;
    }
};