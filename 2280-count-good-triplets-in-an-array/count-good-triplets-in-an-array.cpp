class Solution {
public:
    void updatest(int idx, int l, int r, int target, vector<long long>& st) {
        if (l == r) {
            st[idx] = 1;
            return;
        }
        int mid = l + (r - l) / 2;
        if (target <= mid)
            updatest(2 * idx + 1, l, mid, target, st);
        else
            updatest(2 * idx + 2, mid + 1, r, target, st);

        st[idx] = st[2 * idx + 1] + st[2 * idx + 2];
    }

    long long queryst(int qs, int qe, int idx, int l, int r, vector<long long>&st){
        if(qs > r || qe < l)return 0;
        if (l >= qs && r <= qe) return st[idx];

        int mid = l + (r-l)/2;

        return queryst(qs,qe,2*idx+1,l,mid,st) + queryst(qs,qe,2*idx+2,mid+1,r,st);
    }

    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        int n = nums1.size();

        for (int i = 0; i < n; i++) {
            mp[nums2[i]] = i;
        }

        vector<long long> st(4 * n);
        long long result = 0;

        updatest(0, 0, n - 1, mp[nums1[0]], st);

        for (int i = 1; i < n; i++) {
            int idx = mp[nums1[i]];

            long long leftcommoncount = queryst(0, idx, 0, 0, n - 1, st);
            long long leftuncommoncount = i - leftcommoncount;

            long long elementafteridxnums2 = (n - 1) - idx;
            long long rightcommoncount =
                elementafteridxnums2 - leftuncommoncount;

            result += leftcommoncount * rightcommoncount;

            updatest(0, 0, n - 1, mp[nums1[i]], st);
        }
        return result;
    }
};