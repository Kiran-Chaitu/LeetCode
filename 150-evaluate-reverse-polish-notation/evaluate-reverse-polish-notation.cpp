class Solution {
public:
    int solver(int a, int b , char s){
        if(s=='+') return a+b;
        else if(s=='-') return a-b;
        else if(s=='*') return a*b;
        else return a/b;

    }
    int evalRPN(vector<string>& s) {
        stack<int> num;
        //stack<char> op;
        for(int i=0;i<s.size();i++){
            if((s[i][0]=='+' || s[i][0]=='-' || s[i][0]=='*' || s[i][0]=='/') and (s[i].size()==1)){
                int a=num.top();
                num.pop();
                int b=num.top();
                num.pop();
                int ans=solver(b,a,s[i][0]);
                num.push(ans);
            }
            else{
                num.push(stoi(s[i]));
            }
        }
        return num.top();
    }
};