class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> v(n);
        unordered_map<int,int> mp;
        int sum=0,count = 0;
        v[0]=nums[0];
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            v[i]=sum;
            //mp[sum]++;
        }
        mp[0]=1;
        for(int i =0;i<nums.size();i++){
            
                if(mp.find(v[i] - k) != mp.end()){
                    
                    count+=mp[v[i] - k];
                    mp[v[i]]++;
                }
                else mp[v[i]]++;
            
        }
        return count;

    }
};