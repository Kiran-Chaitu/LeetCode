class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        n--;
        string s="1";
        while(n--){
            string ans="";
            // cout<<"s = "<<s<<endl;
            char ch = s[0];
            int c=0;
            for(auto i:s){
                if(i==ch) c++;
                else{
                    ans+=to_string(c);
                    ans+=ch;
                    ch = i;
                    c=1;
                }
            }
            ans+=to_string(c);
            ans+=ch;
            // cout<<ans<<endl;
            s=ans;
        }
        return s;
    }
};