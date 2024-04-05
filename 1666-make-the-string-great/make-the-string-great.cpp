class Solution {
public:
    string makeGood(string s) {
        ios_base::sync_with_stdio(0);
        stack<char> st;
        //st.push(s[0]);
        for(int i=0;i<s.size();i++){
            if(!st.empty() and islower(st.top()) and isupper(s[i]) and (tolower(s[i]) == st.top())){
                cout<<st.top();
                st.pop();
                
            }
            else if(!st.empty() and isupper(st.top()) and islower(s[i]) and (toupper(s[i]) == st.top())){
                cout<<st.top();
                st.pop();
            }
            else st.push(s[i]);
        }
        s="";
        while(!st.empty()){
            s=st.top() + s;
            st.pop();
        }
        return s;
    }
};