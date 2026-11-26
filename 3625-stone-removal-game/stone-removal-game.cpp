class Solution {
public:
    bool canAliceWin(int n) {
        if(n<=9) return false;
        else if(n<=18) return true;
        bool ans=true;
        int bob=9,alice=10,turn=1;
        while(1){
            if(turn&1){
                if(n< alice) return false;
                n-=alice;
                alice-=2;
                turn++;
            }
            else{
                if(n<bob) return true;
                n-=bob;
                bob-=2;
                turn++;
            }
        }
        return false;
        
    }
};