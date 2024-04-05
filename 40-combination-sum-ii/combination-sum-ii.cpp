class Solution {
public:
    void Combination(vector<int>&v, int target, int ind, int sum, int size, vector<int>ans, set<vector<int>>&s)
{
	if(ind >= size && sum != target)
	{
		return;
	}
	else if(sum == target)
	{
		s.insert(ans);
		return;
	}
	if(sum > target)
	{
		return;
	}
	sum += v[ind];
	ans.push_back(v[ind]);
	Combination(v,target,ind+1,sum,size,ans,s);
    
    while(ind<size-1 && v[ind]==v[ind+1]){
        ind++;
    }
	sum -= v[ind];
	ans.pop_back();
	Combination(v,target,ind+1,sum,size,ans,s);
}
    vector<vector<int>> combinationSum2(vector<int>& v, int target) {
    set<vector<int>>s;
	sort(v.begin(),v.end());
	Combination(v,target,0,0,v.size(),{},s);
	vector<vector<int>>result;
	set<vector<int>>::iterator it;
	for(it = s.begin(); it != s.end(); it++)
	{
		result.push_back(*it);
	}
    return result;
        
    }
};