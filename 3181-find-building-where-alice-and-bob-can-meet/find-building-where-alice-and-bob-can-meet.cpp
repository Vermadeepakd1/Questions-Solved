class Solution {
public:

    int queryst(int start, int end, int idx, int l, int r, int st[], vector<int>&heights){
        if(l > end || r < start)return -1;

        if (l >= start && r <= end) return st[idx];

        int mid = l + (r-l)/2;
        int lidx = queryst(start,end,2*idx+1,l,mid,st,heights);
        int ridx = queryst(start,end,2*idx+2,mid+1,r,st,heights);

        if(lidx == -1)return ridx;
        if(ridx == -1)return lidx;

        return (heights[lidx] >= heights[ridx])?lidx:ridx;
    }

    int rmiq(int st[], vector<int>&heights, int n, int a, int b){
        return queryst(a,b,0,0,n-1,st,heights);
    }

    void buildst(int idx, int l, int r, int* segtree, vector<int>&heights){
        if(l == r){
            segtree[idx] = l;
            return;
        }
        int mid = l + (r-l)/2;
        buildst(2*idx+1, l,mid,segtree,heights);
        buildst(2*idx+2, mid+1,r, segtree,heights);

        int lidx = segtree[2*idx+1], ridx = segtree[2*idx+2];
        if(heights[lidx] >= heights[ridx]){
            segtree[idx] = lidx;
        }else{
            segtree[idx] = ridx;
        }
    }

    int* constructst(vector<int>& heights, int n){
        int *segtree = new int[4*n];
        buildst(0,0,n-1,segtree,heights);
        return segtree;
    }

    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();

        int *segtree = constructst(heights,n);
        vector<int>result;

        for(auto &q: queries){
            int minidx = min(q[0],q[1]);
            int maxidx = max(q[0],q[1]);

            if(minidx == maxidx){
                result.push_back(minidx);
                continue;
            }else if(heights[maxidx] > heights[minidx]){
                result.push_back(maxidx);
                continue;
            }
            int l = maxidx+1;
            int r = n-1;
            int idx = INT_MAX;

            while(l <= r){
                int mid = l + (r-l)/2;
                int rmidx = rmiq(segtree,heights,n,maxidx+1,mid);

                if(rmidx != -1 && heights[rmidx] > max(heights[minidx],heights[maxidx])){
                    idx = min(idx,rmidx);
                    r = mid-1;
                }else l = mid+1;
            }
            if(idx == INT_MAX)result.push_back(-1);
            else result.push_back(idx);
        }
        delete[] segtree;
        return result;
    }
};