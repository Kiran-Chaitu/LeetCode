class Solution {
public:
    int calcualteDifference(vector<int> &arr , int pos,int x){
        int n = arr.size() , sum = 0;
        for(auto i : arr) sum+= abs(arr[pos] - i)/x;
        return sum;
    }
    int minOperations(vector<vector<int>>& grid, int x) {
        int remainder = grid[0][0]%x , c =0;
        vector<int> temp;
        for(int i = 0; i <grid.size();i++){
            for(int j = 0; j < grid[0].size();j++){
                temp.push_back(grid[i][j]);
                if(grid[i][j]%x != remainder) c++;
            }
        }
        if(c!=0) return -1;
        sort(temp.begin() , temp.end());
        int n = temp.size();
        if(n%2==0){
            int sum1 = calcualteDifference(temp , n/2,x);
            int sum2 = calcualteDifference(temp , (n/2)-1,x);
            return min(sum1,sum2);
        }
        int sum = calcualteDifference(temp, n/2,x);
        return sum;
    }
};