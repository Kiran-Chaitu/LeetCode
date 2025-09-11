class Solution {
public:
    string sortVowels(string s) {
        unordered_map<char , int> mp;    
        vector<char> vow = {'a' , 'e' ,'i' , 'o' , 'u' , 'A' , 'E' , 'I' , 'O' , 'U'};
        for(auto i : vow) mp[i]=1;
        vector<char> vowels = {};
        for(auto i : s){
            if(mp[i]) vowels.push_back(i);
        } 
        sort(vowels.begin() , vowels.end());
        int i = 0;
        for(int j = 0 ; j < s.size() ;j++){
            if(mp[s[j]]){
                s[j] = vowels[i++];
            }
        }
        return s;
    }
};