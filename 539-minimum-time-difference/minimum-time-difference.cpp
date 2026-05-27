class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<long long> v;
        for(int i = 0 ; i < timePoints.size() ; i++){
            string hours = timePoints[i].substr(0,2);
            string minutes = timePoints[i].substr(3,2);
            long long total = 0 , h = stoi(hours) , m = stoi(minutes);
            if(h > 12){
                total+=720;
                h-=12;
            }
            total+= (h*60)+(m);
            v.push_back(total);
        }
        sort(v.begin(),v.end());
        long long mini = INT_MAX;
        for(int i = 0; i < v.size()-1;i++){
            mini = min(v[i+1] - v[i] , mini);
        }
        mini = min(mini , ((1440 - v[v.size()-1]) + (v[0])));
        return mini;
    }
};