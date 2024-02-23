class Solution {
public:
    int maxSum(vector<int>& nums) {
        map<int,vector<int>> m;
        for(int i=0;i<nums.size();i++){
            int t=nums[i];
            int maxi=INT_MIN;
            while(t){
                int rm=t%10;
                if(maxi<rm) maxi = rm;
                t/=10;
            }
            m[maxi].push_back(nums[i]);
        }
        int max_sum=-1;
        for(auto i : m){
            sort(i.second.begin(),i.second.end());
            int size = i.second.size();
            if (size >= 2) {
                int sum = i.second[size - 1] + i.second[size - 2];
                if (sum > max_sum) max_sum = sum;
            }
        }
        return max_sum;
    }
};