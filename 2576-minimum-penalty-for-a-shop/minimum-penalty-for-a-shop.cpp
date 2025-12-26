class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size() , c = 0;
        vector<int> pre(n+1) , suf(n+1);
        for(int i = 0 ;i <= n ; i++){
            pre[i] = c;
            if(customers[i]=='N') c++;
        }
        c=0;
        for(int i = n;i>=0;i--){
            if(customers[i] == 'Y') c++;
            suf[i] = c;
        }
        int ans = INT_MAX , sum = 0 , index = -1;
        for(int i = 0; i <= n ;i++){
            sum = pre[i] + suf[i];
            if(ans > sum){
                ans = sum;
                index = i;
            }
        }
        return index;

    }
};