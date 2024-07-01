class Solution {
public:
    bool checkIfOdd(int n){
        if(n&1) return true;
        return false;
    }
    bool threeConsecutiveOdds(vector<int>& arr) {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        int n = arr.size();
        if(n<3) return false;
        int oddCount = 0;
        for(int i=0;i<3;i++){
            if(checkIfOdd(arr[i])) oddCount++;
        }
        if(oddCount==3) return true;
        for(int i=3;i<n;i++){
            if(checkIfOdd(arr[i])) oddCount++;
            if(checkIfOdd(arr[i-3])) oddCount--;
            if(oddCount==3) return true;
        }
        return false;

    }
};