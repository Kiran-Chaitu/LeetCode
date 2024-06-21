class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        long long int totalSum=0;
        int n=grumpy.size();
        for(int i=0;i<n;i++){
            if(grumpy[i]==0)    totalSum+=customers[i];
        }
        int i=0;
        while(i<minutes){
            if(grumpy[i]==1) totalSum+=customers[i];
            i++;
        }
        long long int maxi = totalSum; 
        int j=minutes;
        i=0;
        while(j<n){
            if(grumpy[i]==1) totalSum-=customers[i];
            if(grumpy[j]==1) totalSum+=customers[j];
            i++;
            j++;
            maxi = max(totalSum,maxi);
        }
        return maxi;

    }
};