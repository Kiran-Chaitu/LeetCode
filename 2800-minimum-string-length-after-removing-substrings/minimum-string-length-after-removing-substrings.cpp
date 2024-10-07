class Solution {
public:
    int minLength(string s) {
        stack<int> st;
        for(int i=0;i<s.size();i++){
            if(!st.empty()){
                if(s[i]=='B' and st.top()=='A'){
                    st.pop();
                }
                else if(s[i]=='D' and st.top()=='C'){
                    st.pop();
                }
                else{
                    st.push(s[i]);
                }
            }
            else st.push(s[i]);
        }
        return st.size();
    }
};