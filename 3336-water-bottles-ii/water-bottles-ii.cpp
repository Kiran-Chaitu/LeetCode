class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int tot = 0 , empty = 0;
        tot+=numBottles;
        empty+=numBottles;
        while(empty >= numExchange){
            tot++;
            empty++;
            empty -= numExchange;
            numExchange++;
        }
        return tot;
    }
};