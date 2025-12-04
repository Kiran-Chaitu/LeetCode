class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        unordered_map<string , unordered_map<string , int>> mp;
        int n = messages.size();
        int maxi = 0;
        for(int i=0;i<n;i++){
            string temp = messages[i] , ss ="";
            int j = 0 , m = temp.size();
            while(j<m){
                if(temp[j]==' '){
                    mp[senders[i]][ss]++;
                    ss="";
                    j++;
                }
                ss+=temp[j++];
            }
            mp[senders[i]][ss]++;
        }
        priority_queue<string> pq;
        for(auto i: mp){
            int sum =0;
            for(auto j : i.second){
                sum+=j.second;
            }
            maxi = max(maxi , sum);
            mp[i.first]["SUM"] = sum;
        }
        for(auto i:mp){
            if(mp[i.first]["SUM"]==maxi) pq.push(i.first);
        }
        return pq.top();
    }
};