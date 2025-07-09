class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        long long int maxi = 0 , sum =0 , n = startTime.size();
        vector<int> v = {startTime[0]};
        for(int i=0;i<n-1;i++){
            v.push_back(startTime[i+1] - endTime[i]);
        }
        v.push_back(eventTime - endTime[n-1]);
        k++;
        int i=0 ;
        while(i < k){
            sum+=v[i++];
        }
        maxi = sum;
        while(i < v.size()){
            sum-=v[i-k];
            sum+=v[i++];
            maxi = max(maxi , sum);
        }
        return maxi;
    }
};