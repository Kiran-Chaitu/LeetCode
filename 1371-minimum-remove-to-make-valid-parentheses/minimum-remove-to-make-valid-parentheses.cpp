class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n=s.size();
        stack<int>st;
        for(int i=0;i<n;i++){
            if(s[i]=='(') {
                st.push(i);
            } 
            else if(s[i]==')'){
                if(!st.empty())     st.pop();
                else    s[i]='1';
            }
        }
        while(!st.empty()){
            s[st.top()]='1';
            st.pop();
        }
        string ans="";
        for(int i=0;i<n;i++){
            if(s[i]!='1')
                ans+=(s[i]);
        }
        return ans;
    }
};