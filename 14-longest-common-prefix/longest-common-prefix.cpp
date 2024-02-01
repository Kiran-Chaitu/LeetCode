class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
      // vector <string> s;
       string res = "";
       res=strs[0];
       for(int i = 1 ; i < strs.size() ; i++) {
           string s = "";
           
           for(int j = 0 ;j < res.size() ; j++){
               if(strs[i][j] == res[j]){

                   s += strs[i][j];
               }
               else{
                   res = s;
                   break;
               }
           }
       }
       return res;
    }
};