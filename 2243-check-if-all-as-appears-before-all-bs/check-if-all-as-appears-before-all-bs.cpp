class Solution {
public:
    bool checkString(string s) {
        int ind = -1;
        for(int i = 0 ;i < s.size(); i++){
            if(s[i] == 'a'){
                ind = i;
            }
        }
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'b' and ind > i){
                return false;
            }
        }
        return true;
    }
};