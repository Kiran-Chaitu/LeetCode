class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        unordered_map<string , int> mp;
        for(auto i : wordList) mp[i]++;
        if(mp.find(endWord)== mp.end()) return 0;
        q.push({beginWord , 1});
        if(mp.find(beginWord)!=mp.end()) mp.erase(beginWord);
        while(!q.empty()){
            if(q.front().first == endWord) return q.front().second;
            string word = q.front().first;
            int level = q.front().second;
            for(int i = 0; i < word.size() ;i++ ){
                char original = word[i];
                for(char ch = 'a' ; ch <='z';ch++){
                    word[i] = ch;
                    if(mp.find(word)!=mp.end()){ 
                        q.push({word , level+1});
                        mp.erase(word);
                    }
                }
                word[i] = original;
            }
            // cout<<endl;
            q.pop();
        }
        return 0;
    }
};