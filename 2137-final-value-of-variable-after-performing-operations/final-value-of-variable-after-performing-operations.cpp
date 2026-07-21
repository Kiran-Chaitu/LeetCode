class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int val  = 0 ;
        for(auto i : operations){
            if(i[0] == '-' || i[2] == '-') val--;
            else val++;
        }
        return val;
    }
};