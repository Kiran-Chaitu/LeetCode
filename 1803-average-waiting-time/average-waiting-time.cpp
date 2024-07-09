class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        double waitingTime=0,ans=customers[0][0];
        int n = customers.size();
        for(int i=0;i<n;i++){
            if(ans < customers[i][0]) ans = customers[i][0];
            ans+=customers[i][1];
            waitingTime+=ans - customers[i][0];
            //cout<<ans<<" "<<waitingTime<<endl;
        }
        return waitingTime/n;
    }
};