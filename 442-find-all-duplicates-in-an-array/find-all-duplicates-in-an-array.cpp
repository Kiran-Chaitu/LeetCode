class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        int n=nums.size();
        vector<int> fr(n+1,0);
        vector<int> v;
        for(int i : nums){
            if(fr[i] > 0) v.push_back(i);
            fr[i]++;
        }
        return v;
    }
};