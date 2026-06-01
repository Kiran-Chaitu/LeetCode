class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin() , cost.end());
        int sum = 0 , n = cost.size() , i = n-1;
        while(i >=0){
            sum+=cost[i--];
            if(i>=0) sum+=cost[i--];
            i--;
        }
        return sum;
    }
};