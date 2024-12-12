class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        long long ans=0;
        for(auto i:gifts) pq.push(i);
        while(k--){
            pq.push(floor(sqrt(pq.top())));
            pq.pop();
        }
        while(!pq.empty()){
            ans+=pq.top();
            pq.pop();
        }
        return ans;
    }
};