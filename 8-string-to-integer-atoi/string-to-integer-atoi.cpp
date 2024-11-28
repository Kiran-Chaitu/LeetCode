class Solution {
public:
    int myAtoi(string s) {
        bool isMinus = false;
        long long int ans=0,mini = INT_MIN,maxi=INT_MAX,i=0;
        while(s[i]==' ') i++;
        if(s[i]=='+' || s[i]=='-'){
            isMinus = s[i]=='-';
            i++;
        }
        for(;i<s.size();i++){
            if(s[i]>='0' and s[i]<='9'){
                if(ans > (maxi - (s[i]-'0'))/10)    return (isMinus) ? mini : maxi;
                ans = ans*10 + (s[i]-'0');
            }
            else break;
        }
        return (isMinus) ?  -(ans) : ans;
    }
};