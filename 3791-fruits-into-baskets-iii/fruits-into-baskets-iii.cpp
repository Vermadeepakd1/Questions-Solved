class Solution {
public:

    void buildst(int i, int l, int r, vector<int>&baskets, vector<int>&st){
        if(l==r){
            st[i] = baskets[l];
            return;
        }
        int mid = l + (r-l)/2;
        buildst(2*i+1,l,mid,baskets,st);
        buildst(2*i+2,mid+1,r,baskets,st);

        st[i] = max(st[2*i+1],st[2*i+2]);
    }

    bool queryst(int i, int l, int r, int target, vector<int>&st){
        if(st[i] < target)return false;
        if(l==r && st[i] >= target){
            st[i] = -1;
            return true;
        }
        int mid = l +(r-l)/2;
        bool placed = false;
        if(st[2*i+1] >= target){
            placed = queryst(2*i+1, l, mid, target, st);
        }else{
            placed = queryst(2*i+2, mid+1,r,target,st);
        }
        st[i] = max(st[2*i+1],st[2*i+2]);
        return placed;
    }

    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size();
        vector<int> st(4*n);
        buildst(0,0,n-1,baskets,st);
        int cnt = 0;

        for(int f : fruits){
            if(!queryst(0,0,n-1,f,st))cnt++;
        }
        return cnt;
    }
};