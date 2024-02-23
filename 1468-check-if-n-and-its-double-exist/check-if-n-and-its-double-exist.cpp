class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
       unordered_map<int,int>mp;
       for(int i=0; i<arr.size(); i++){
          mp[arr[i]]++;
       }
       for(auto i : mp){
            if(mp.find(2 * (i.first)) != mp.end()){
                if(i.first==0 and  mp[0] > 1) return true;
                else if(i.first==0 and mp[0]<=1) return false;
                return true;
            } 
       }
       return false;

    }
};