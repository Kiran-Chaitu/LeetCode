class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = 0 , n = cardPoints.size();
        for(auto i : cardPoints) sum += i;
        if(k == n) return sum;
        int maxi = INT_MIN , temp = 0;
        for(int i = 0; i < n;i++){
            temp += cardPoints[i];
            if(i >=  n - k - 1){
                maxi = max(maxi ,sum - temp);
                temp -= cardPoints[i - (n - k)+1];
            }
        }
        return maxi;
    }
};