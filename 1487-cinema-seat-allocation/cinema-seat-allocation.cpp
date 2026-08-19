class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,unordered_set<int>> mp;
        for(auto i : reservedSeats){
            int r = i[0] , c = i[1];
            if(c >=2 and c<=3){
                mp[r].insert(1);
            }
            if(c>=4 and c<=5){
                mp[r].insert(1);
                mp[r].insert(2);
            }
            if(c>=6 and c<=7){
                mp[r].insert(2);
                mp[r].insert(3);
            }
            if(c>=8 and c<=9){
                mp[r].insert(3);
            }
        }
        // cout<<mp.size()<<endl;
        int temp = n - mp.size();
        int ans = 0;
        for(auto i : mp){
            auto s = i.second;
            if(s.find(1)==s.end() and s.find(3)==s.end()) ans+=2;
            else if(s.find(1)==s.end() or s.find(2)==s.end() or s.find(3)== s.end()) ans++;
            // cout<<i.first<<" "<<ans<<endl;
        }
        return ans + (temp *2);
    }
};