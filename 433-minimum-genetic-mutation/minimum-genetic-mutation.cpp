class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        queue<pair<string,int>> q;
        unordered_map<string , int> mp;
        for(auto i : bank) mp[i]++;
        if(mp.find(endGene)== mp.end()) return -1;
        vector<char> v = {'A' , 'C' , 'G' , 'T'};
        q.push({startGene , 1});
        if(mp.find(startGene)!=mp.end()) mp.erase(startGene);
        while(!q.empty()){
            if(q.front().first == endGene) return q.front().second-1;
            string word = q.front().first;
            int level = q.front().second;
            for(int i = 0; i < word.size() ;i++ ){
                for(char ch : v){
                    string prefix ="" , suffix="";
                    prefix = word.substr(0 ,i);
                    if(i!=word.size()-1) suffix = word.substr(i+1);
                    string temp = prefix + ch + suffix;
                    // cout<<prefix<<"; ";
                    if(temp != word and mp.find(temp)!=mp.end()){ 
                        q.push({temp , level+1});
                        mp.erase(temp);
                    }
                }
            }
            // cout<<endl;
            q.pop();
        }
        return -1;
    }
};