class Solution {
public:
    int numTeams(vector<int>& rating) {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        int ans=0,n=rating.size();

        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                for(int k=j+1;k<n;k++){
                    if((rating[i] < rating[j] and rating[j] < rating[k]) || (rating[i] > rating[j] and rating[j] > rating[k])){
                         //cout<<rating[i]<<" "<<rating[j]<<" "<<rating[k]<<endl;
                         ans++;
                    }

                }
            }
        }
        return ans;
        
    }
};