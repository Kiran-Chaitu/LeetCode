class Solution {
public:
    int countSeniors(vector<string>& details) {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        int ans = 0;
        for(int i=0;i<details.size();i++){
            string str = "";
            str+=(details[i][11]);
            str+=(details[i][12]);
            int num =stoi(str);
            if(num>60) ans++;
        }
        return ans;
    }
};