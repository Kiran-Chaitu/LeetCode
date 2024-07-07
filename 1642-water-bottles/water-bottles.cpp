class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        long long int ans=0,emptyBottles=0;
        while(numBottles !=0 ){
            ans+=numBottles;
            emptyBottles += numBottles;
            numBottles = 0;
            int k=(emptyBottles)/numExchange;
            if(k==0) break;
            emptyBottles%= numExchange;
            numBottles+= (k);
        }
        return ans;
    }
};