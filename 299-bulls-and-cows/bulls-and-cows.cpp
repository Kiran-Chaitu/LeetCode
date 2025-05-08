class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char,int> mp;
        int a =0 , c = 0;
        for(int i=0;i<secret.size() ; i++){
            if(secret[i] == guess[i]){ 
                a++;
                guess[i]='K';
            }
            else mp[secret[i]]++;
        }
        for(auto i:guess){
            if(i=='K') continue;
            if(mp[i] > 0){
                c++;
                mp[i]--;
            }
        }
        string s="";
        s+=to_string(a) + 'A' + to_string(c) + 'B';
        return s;
    }
};