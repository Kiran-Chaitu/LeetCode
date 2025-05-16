class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int c=0,i=0,j=0,n=nums.size(),maxi=INT_MIN;
        queue<int> q;
        while(j<n){
            if(nums[j]==0){
                c++;
                q.push(j);
            }
            while(c > k){
                i = q.front() + 1;
                q.pop();
                c--;
            }

            maxi=max(maxi,j-i+1);
            j++;
        }
        return maxi;

    }
};