class Solution {
public:
    string simplifyPath(string path) {
        string s = "";
        stack<string> st;
        int i=0 , n =path.size();
        while(i< n){
            string temp = "";
            while( i<n and path[i]!='/'){
                temp += path[i++];
            }
            if(temp == ".."){
                if(!st.empty())    st.pop();
            }
            else if(temp == ".") continue;
            else if(temp!="")   st.push(temp);
            while(i<n and path[i]=='/') i++;
        }
        while(!st.empty()){ 
            
            s= '/' + st.top() + s;
            
            st.pop();
        }
        if(s=="") s= "/";
        return s;
    }
};