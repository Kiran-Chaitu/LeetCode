class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<string> st;
        string ans="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push("(");
                if(st.size()>1) ans+=s[i];
            } 
            else{
                if(st.size()>1) ans+=s[i];
                st.pop();
                
            }
        }
        return ans;
    }
};