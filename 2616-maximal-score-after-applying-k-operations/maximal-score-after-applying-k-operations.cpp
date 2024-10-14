class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans=0;
        priority_queue<int> pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        while(k){
            ans+=pq.top();
            double kc = pq.top();
            //cout<<ans<<" "<<kc<<endl;
            pq.pop();
            kc = ceil(kc/3);
            pq.push((int)kc);
            k--;
        }
        return ans;
    }
};