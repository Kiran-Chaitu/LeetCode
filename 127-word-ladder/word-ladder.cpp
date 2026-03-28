class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,int> mp;
        for(auto i : wordList){
            mp[i]=1;
        }
        queue<pair<string,int>> q;
        q.push({beginWord , 1});
        if(mp.find(beginWord)!=mp.end()){
            mp.erase(beginWord);
        }
        while(!q.empty()){
            string word = q.front().first;
            int level = q.front().second;
            q.pop();
            if(word == endWord) return level;
            for(int i = 0; i < word.size();i++){
                char org = word[i];
                for(auto alp = 'a' ; alp <='z';alp++){
                    word[i] = alp;
                    if(mp.find(word)!=mp.end()){
                        q.push({word , level+1});
                        mp.erase(word);
                    }
                }
                word[i] = org;
            }
        }
        return 0;
    }
};