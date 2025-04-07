class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> less , more;
        int c=0;
        for(auto i:nums){
            if(i==pivot) c++;
            else if(i > pivot) more.push_back(i);
            else less.push_back(i);
        }
        int k=0;
        for(int i=0;i<less.size();i++ , k++) nums[k] = less[i] ;
        while(c--) nums[k++]=pivot;
        for(int i=0;i<more.size();i++ , k++) nums[k] = more[i];
        return nums;
    }
};