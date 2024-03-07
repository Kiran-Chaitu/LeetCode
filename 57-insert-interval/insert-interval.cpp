class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        ios_base::sync_with_stdio(0);
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        vector<vector<int>> ans;
        if(n==1) return intervals;
        int i=0;
        while(i<n-1){
            if(intervals[i][1]>=intervals[i+1][0]){
                int j=i+1,maxi=-1,mi;
                for(;j<n;j++){
                    //cout<<intervals[j-1][1]<<" "<<intervals[j][0]<<endl;
                    if(maxi<intervals[j-1][1]){
                        maxi=intervals[j-1][1];
                        mi=j-1;
                    }
                    if(intervals[mi][1]<intervals[j][0]) break;
                }
                if(intervals[mi][1] >= intervals[i][1] and intervals[j-1][1]>intervals[mi][1]) ans.push_back({intervals[i][0] , intervals[j-1][1]});
                else if(intervals[mi][1] >= intervals[i][1]) ans.push_back({intervals[i][0] , intervals[mi][1]});
                else ans.push_back({intervals[i][0] , intervals[i][1]});
                i=j;
            }
            else{
                ans.push_back({intervals[i][0] , intervals[i][1]});
                i++;
            }
        }
        int k=ans.size();
        if(ans[k-1][1]<intervals[n - 1][1]) ans.push_back({intervals[n-1][0] , intervals[n-1][1]});
        return ans; 
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        return merge(intervals);
    }
};