class Solution {
public:
    void balance(multiset<int> &low , multiset<int> &high){
        if(low.size() > high.size()  + 1){
            high.insert(*low.rbegin());
            low.erase(prev(low.end()));
        }
        if( high.size()  > low.size()){
            low.insert(*high.begin());
            high.erase(high.begin());
        }
    }
    vector<double> medianSlidingWindow(vector<int>& nums, int k) { 
        vector<double> ans;
        multiset<int> low, high;
        for(int i=0;i<nums.size();i++){
            if(low.empty() or *low.rbegin() >= nums[i]) low.insert(nums[i]);
            else high.insert(nums[i]);
            balance(low,high);

            if(i>=k){
                int val = nums[i-k];
                if(val <= *low.rbegin()){
                    low.erase(low.find(val));
                }
                else{ 
                    high.erase(high.find(val));
                }
                balance(low,high);
            }
            

            if(i >= k-1){
                if(k&1){
                    ans.push_back((double)*low.rbegin());
                }else{
                    ans.push_back((double)(((double)*low.rbegin() + (double)*high.begin())/2.0) );
                }
            }


        }
        return ans;
    }
};