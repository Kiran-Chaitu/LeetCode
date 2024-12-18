class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> st;
        vector<int> nxt(prices.size(),-1);
        int n=prices.size();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() and st.top() > prices[i]){
                st.pop();
            }
            if(!st.empty()) nxt[i] = st.top();
            st.push(prices[i]);
        }
        for(int i=0;i<n;i++){    
            if(nxt[i]!=-1)  prices[i]-=nxt[i];
            //cout<<nxt[i]<<" ";
        }
        return prices;
    }
};