class Solution {
public:
    bool ispal(string s){
        int l=0,r=s.size()-1;
        while(l<=r){
            if(s[l]!=s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        for(auto i:words){
            if(ispal(i)) return i;
        }
        return "";
    }
};