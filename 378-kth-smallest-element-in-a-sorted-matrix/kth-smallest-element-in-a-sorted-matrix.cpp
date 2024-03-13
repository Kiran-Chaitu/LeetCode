class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int , vector<int> , greater<int>> pq;
        int n=matrix.size(),i=1;;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                pq.push(matrix[i][j]);
            }
        }
       /* while(!pq.empty()){
            cout<<pq.top()<<" ";
            pq.pop();
        }*/
       while(i<k){
            i++;
            pq.pop();
        } 
        //return 0;
        return pq.top();
    }
};