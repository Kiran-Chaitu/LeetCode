class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int totalApples  =0 , totalCapacity = 0 , requiredBoxes=0;
        for(auto i : apple ) totalApples+=i;
        sort(capacity.begin() , capacity.end());
        for(int i = capacity.size()-1;i>=0;i--){
            totalCapacity+=capacity[i];
            requiredBoxes++;
            if(totalCapacity >= totalApples) return requiredBoxes;
        }
        return requiredBoxes;
    }
};