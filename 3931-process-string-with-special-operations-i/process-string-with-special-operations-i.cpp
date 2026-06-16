class Solution {
public:
    string rev(string s){
        int i = 0 , j = s.size()-1;
        while(i < j){
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;j--;
        }
        return s;
    }
    string processStr(string s) {
        string res = "";
        for(auto i : s){
            if(i >= 'a' and i <= 'z'){
                res+=i;
            }else if(i == '*'){
                if(!(res.empty()) )res.pop_back();
            }else if(i == '#'){
                res+=res;
            }
            else if(i == '%'){
                res = rev(res);
            }
        }
        return res;
    }
};