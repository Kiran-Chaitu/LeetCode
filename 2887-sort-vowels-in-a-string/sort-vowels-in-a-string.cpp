class Solution {
public:
    
    bool isVowel(char ch){
        unordered_map<char , int> mp;    
        vector<char> vowels = {'a' , 'e' ,'i' , 'o' , 'u' , 'A' , 'E' , 'I' , 'O' , 'U'};
        for(auto i : vowels) mp[i]=1;
        return mp[ch];

    }
    string sortVowels(string s) {
        vector<char> vowels = {};
        for(auto i : s){
            if(isVowel(i)) vowels.push_back(i);
        } 
        sort(vowels.begin() , vowels.end());
        int i = 0;
        for(int j = 0 ; j < s.size() ;j++){
            if(isVowel(s[j])){
                s[j] = vowels[i++];
            }
        }
        return s;
    }
};