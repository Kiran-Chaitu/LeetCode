class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        long long ans = LLONG_MAX ,n = nums.size();
        priority_queue<int> f;
        priority_queue<int, vector<int> , greater<int>> s;
        long long sum =0 ;
        vector<long long> pre(n) , suf(n);
        for(int i=0;i<n;i++){
            if(f.size() >= (n/3) and nums[i] < f.top()){
                sum-=f.top();
                sum+=nums[i];
                f.pop();
                f.push(nums[i]);
            }
            else if(f.size() < (n/3)){
                sum+=nums[i];
                f.push(nums[i]);
            }
            pre[i] = sum;
        }
        sum=0;
        for(int i = n-1;i>=0;i--){
            if(s.size() >= (n/3) and nums[i] > s.top()){
                sum-=s.top();
                sum+=nums[i];
                s.pop();
                s.push(nums[i]);
            }
            else if(s.size() < (n/3)){
                sum+=nums[i];
                s.push(nums[i]);
            }
            suf[i] = sum;
        }
        for(int i=(n/3)-1;i<n-(n/3);i++){
            ans = min(ans , pre[i] - suf[i+1]);
        }
        return ans;
    }
};