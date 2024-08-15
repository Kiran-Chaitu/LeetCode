class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        int a=0,b=0;
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5) a++;
            else if(bills[i]==10){
                if(a>0){
                    a--;
                    b++;
                }
                else return false;
            }
            else{
                if(a>0 and b>0){
                    a--;
                    b--;
                }
                else if(a>=3 and b==0){
                    a-=3;
                }
                else return false;
            }
        }
        return true;
    }
};