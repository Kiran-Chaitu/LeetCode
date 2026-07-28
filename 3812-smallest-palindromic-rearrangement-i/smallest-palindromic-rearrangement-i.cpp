class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        //sort(s.begin() ,s.end());
        map<char,int> mp;
        for(auto i:s) mp[i]++;
        char ch='+';
        string ns = "";
        for(auto i:mp){
            if(i.second & 1){
                int k = (i.second-1)/2;
                while(k--) ns+=i.first;
                ch=i.first;
            }
            else{
                int k = i.second/2;
                while(k--) ns+=i.first;
            }
        }
        string rev = ns;
        reverse(rev.begin() , rev.end());
        // cout<<ns<<" "<<rev<<" "<<ch<<endl;
        if(ch=='+') s = ns + rev;
        else{
            s=ns;
            s+=ch;
            s+=rev;
        }
        return s;
    }
};