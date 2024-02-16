class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 1;
        int mini,maxi,minn=INT_MAX,maxn=INT_MIN;
        for(int i=0;i<n;i++){
            if(nums[i]<minn){
                minn=nums[i];
                mini=i;
            }
            if(nums[i]>maxn){
                maxn=nums[i];
                maxi=i;
            }
        }
        //cout<<maxn<<" "<<minn;
       // int x=0,y=0;
       /* for(int i=0;i<n;i++){
            if(nums[i]==maxn) x=i;
            if(nums[i]==minn) y=i;
        }
        int front=max(x,y);
        for(int i=n-1;i>=0;i--){
            if(nums[i]==maxn) x=i;
            if(nums[i]==minn) y=i;
        }
        int back=max(x,y);
        for(int i=0;i<n;i++){
            if(nums[i]==maxn || nums[i]==minn){
                x=i;
                break;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(nums[i]==maxn || nums[i]==minn){
                y=i;
                break;
            }
        }
        int sum=x+y;
        */
        int x=max(mini,maxi);
        int y=max(n-1-mini,n-1-maxi);
        int a=min(mini,maxi);
        int sum=a+(n-x);
        if(x<y and x<sum) return x+1;
        else if(y<sum) return y+1;
        else return sum+1;

        return 0;
    }
};