class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long maximumHappiness = 0 , decreasedHappiness = 0;
        sort(happiness.begin() , happiness.end());
        int n = happiness.size() , j =0;
        for(int i=n-1; i>=0 and j <k ; i-- ,j++){
            if(happiness[i] - decreasedHappiness > 0){
                maximumHappiness+=(happiness[i] - decreasedHappiness);
                decreasedHappiness++;
            }
            else break;
        }
        return maximumHappiness;
    }
};