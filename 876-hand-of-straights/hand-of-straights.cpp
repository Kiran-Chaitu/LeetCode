class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0) return false;
        map<int,int> mp;
        for(int i=0;i<hand.size();i++){
            mp[hand[i]]++;
        }
        while(mp.size()!=0){
            //cout<<mp.size()<<"\n";
            vector<int> v;
            int j=0;
            for(auto i: mp){
                if(j==groupSize) break;
                v.push_back(i.first);
                //cout<<i.first<<" ";
                mp[i.first]--;
                if(j!=0){
                    if(abs(i.first - v[j-1]) != 1) return false;
                }
                j++;
                if(mp[i.first]==0) mp.erase(i.first);
                
            }
            if(v.size()!=groupSize) return false;
            //cout<<"\n";
        }
        return true;
        
    }
};