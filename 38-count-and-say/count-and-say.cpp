class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        n--;
        string s="1";
        while(n--){
            string dum="";
            char thingari = s[0];
            int c=0;
            for(auto i:s){
                if(i==thingari) c++;
                else{
                    dum+=to_string(c);
                    dum+=thingari;
                    thingari = i;
                    c=1;
                }
            }
            dum+=to_string(c);
            dum+=thingari;
            s=dum;
        }
        return s;
    }
};