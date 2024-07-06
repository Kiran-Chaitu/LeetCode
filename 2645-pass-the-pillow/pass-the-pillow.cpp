class Solution {
public:
    int passThePillow(int n, int time) {
        bool check=true;int i=1;
        while(time--){
            if(check) i++;
            else i--;
            if(time==0) return i;
            if(check and i==n)  check=false;
            if(!check and i==1) check = true;
        }
        return i;
    }
};