class Solution {
    vector<int> parent, rank;

    int find(int x) {
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }

    bool setunion(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) return false;
        if (rank[rootX] > rank[rootY]) parent[rootY] = rootX;
        else if (rank[rootX] < rank[rootY]) parent[rootX] = rootY;
        else { parent[rootX] = rootY; rank[rootY]++; }
        return true;
    }

    bool check(int n, const vector<vector<int>>& edges, int k, int mid, int mandatory_count) {
        parent.assign(n, 0);
        iota(parent.begin(), parent.end(), 0);
        rank.assign(n, 1);
        int edges_count = 0;

        for (const auto& e : edges) {
            if (e[3] == 1) {
                if (e[2] < mid) return false; 
                if (!setunion(e[0], e[1])) return false; 
                edges_count++;
            }
        }

        for (const auto& e : edges) {
            if (e[3] == 0 && e[2] >= mid) {
                if (setunion(e[0], e[1])) edges_count++;
            }
        }

        for (const auto& e : edges) {
            if (e[3] == 0 && e[2] < mid && 2 * e[2] >= mid && k > 0) {
                if (setunion(e[0], e[1])) {
                    edges_count++;
                    k--;
                }
            }
        }

        return edges_count == n - 1;
    }

public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        int mandatory_count = 0;
        for (const auto& e : edges) if (e[3] == 1) mandatory_count++;

        if (mandatory_count > n - 1) return -1;

        int l = 1, r = 200000; 
        int ans = -1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (check(n, edges, k, mid, mandatory_count)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return ans;
    }
};