class NumArray {
public:
    int n;
    vector<int> segtree;

    void buildsegtree(int idx, int l, int r, vector<int> &nums){
        int mid = l + (r-l)/2;
        if(l == r){
            segtree[idx] = nums[l];
            return;
        }
        buildsegtree(2*idx+1,l,mid,nums);
        buildsegtree(2*idx+2,mid+1,r,nums);

        segtree[idx] = segtree[2*idx+1] + segtree[2*idx+2];
    }

    void updatesegtree(int i,int l, int r,  int index, int val){
        int mid = l+(r-l)/2;

        if(l==r){
            segtree[i]= val;
            return;
        }
        else if(index > mid){
            updatesegtree(2*i+2,mid+1,r,index,val);
        }else{
            updatesegtree(2*i+1,l,mid,index,val);
        }
        segtree[i] = segtree[2*i+1]+segtree[2*i+2];
    }

    int findsum(int idx, int l, int r, int left, int right){
        if(l >= left && r <= right){
            return segtree[idx];
        }
        if(l > right || r < left){
            return 0;
        }
        int mid = l + (r-l)/2;
        return findsum(2*idx+1,l,mid,left,right ) + findsum(2*idx+2,mid+1,r,left,right);
    }

    NumArray(vector<int>& nums) {
        n = nums.size();
        segtree.resize(4*n);
        buildsegtree(0,0,n-1,nums);
    }
    
    void update(int index, int val) {

        updatesegtree(0,0,n-1,index,val);
    }
    
    int sumRange(int left, int right) {
        return findsum(0,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */