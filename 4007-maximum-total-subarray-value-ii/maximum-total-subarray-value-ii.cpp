class Solution {
public:
    void buildst(int i, int l, int r, vector<int>& nums,
                 vector<pair<int, int>>& st) {
        if (l == r) {
            st[i].first = nums[l];
            st[i].second = nums[l];
            return;
        }
        int mid = l + (r - l) / 2;
        buildst(2 * i + 1, l, mid, nums, st);
        buildst(2 * i + 2, mid + 1, r, nums, st);

        st[i].first = max(st[2 * i + 1].first, st[2 * i + 2].first);
        st[i].second = min(st[2 * i + 1].second, st[2 * i + 2].second);
    }

    pair<int, int> queryst(int i, int l, int r, int s, int e,
                           vector<pair<int, int>>& st) {
        if (l > e || r < s) {
            return {-1, INT_MAX};
        }
        if (l >= s && r <= e)
            return st[i];

        int mid = l + (r - l) / 2;
        pair<int, int> f = queryst(2 * i + 1, l, mid, s, e, st);
        pair<int, int> g = queryst(2 * i + 2, mid + 1, r, s, e, st);

        return {max(f.first, g.first), min(f.second, g.second)};
    }

    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();

        vector<pair<int, int>> st(4*n);
        buildst(0, 0, n - 1, nums, st);

        priority_queue<pair<int, pair<int, int>>> pq; // val,l,r

        for (int i = 0; i < n; i++) {
            pair<int, int> mm = queryst(0, 0, n - 1, i, n - 1, st);
            cout << mm.first << " " << mm.second << endl;
            pq.push({mm.first - mm.second, {i, n - 1}});
        }

        long long ans = 0;

        int cnt = 0;
        while (cnt < k) {
            auto t = pq.top();
            pq.pop();
            ans += t.first;
            auto [l, r] = t.second;

            if (l < r) {
                pair<int, int> mm = queryst(0, 0, n - 1, l, r - 1, st);
                pq.push({mm.first - mm.second, {l, r - 1}});
            }

            cnt++;
        }
        return ans;
    }
};