class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> mp;
        for(auto i: text) mp[i]++;
        int mini = INT_MAX;
        string temp = "balloon";
        for(auto i : temp){
            if(i == 'l' || i == 'o') mini = min(mini, mp[i]/2);
            else mini = min(mini , mp[i]);
        }
        return mini;
    }
};