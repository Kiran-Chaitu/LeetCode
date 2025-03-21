
#define ll long long 
class NumArray {
public:
    ll n;
    vector<ll> Tree;
    NumArray(vector<int>& nums) {
        n = nums.size();
        Tree.resize(n*4 , 0);
        build(nums , 0 , 0, n-1);
    }
    void build(vector<int> &v , ll node , ll ss , ll se){
        if(ss==se){
            Tree[node] = v[ss];
            return;
        }
        ll mid = (ss + se)>>1;
        build(v , 2*node +1 , ss , mid);
        build(v, 2 * node +2 , mid+1 , se);
        Tree[node] = Tree[2 * node +1 ] + Tree[2 * node +2];
    } 
    void updateTree(ll node ,ll pos, ll val, ll ss, ll se){
        if(ss == pos and ss==se){
            Tree[node] = val;
            return;
        }
        ll mid = (ss + se)>>1;
        if(pos>=ss and pos<=mid) updateTree(2*node+1 ,pos, val, ss , mid );
        if(pos >=mid+1 and pos<=se) updateTree(2 * node+2,pos , val , mid+1,se );
        Tree[node] = Tree[2* node +1] + Tree[2*node+2];
    }
    void update(int index, int val){
        updateTree(0,index,val,0 , n-1);
    }
    ll query(ll node , ll qs , ll qe , ll ss , ll se){
        if(qs > se || qe < ss)  return 0;
        if(ss >= qs and se <= qe){
            return Tree[node];
        }
        ll mid = (ss + se)>>1;
        ll left = query(2*node+1 , qs,qe,ss,mid);
        ll right = query(2*node+2 , qs,qe,mid+1,se);
        return left+right;
    }
    int sumRange(int left, int right) {
        return  query(0 , left , right , 0 , n-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */