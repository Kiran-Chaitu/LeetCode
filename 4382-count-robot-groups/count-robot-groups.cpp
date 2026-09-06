#define ll long long
class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        int n = position.size() , ans = n;
        int mini = speed.back();
        for(int i = n-2 ; i >=0 ; i--){
            if(mini < speed[i] || position[i+1] - position[i] <= distance) ans--;
            else mini = speed[i];
        }
        return ans;
    }
};