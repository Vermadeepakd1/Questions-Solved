class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> adj(n);
        unordered_map<int, vector<int>> mp; // number- indexes

        for (int i = n-1; i>=0; i--) {
            mp[arr[i]].push_back(i);
        }

        vector<int> visited(n, false);
        visited[0] = true;

        int steps = 0;

        queue<int> q;
        q.push(0);

        while (!q.empty()) {
            int x = q.size();

            for (int i = 0; i<x; i++) {
                int t = q.front();
                q.pop();

                if (t == n - 1)
                    return steps;

                if (t - 1 >= 0 && !visited[t - 1]) {
                    q.push(t - 1);
                    visited[t - 1] = true;
                }
                if (t + 1 < n && !visited[t + 1]) {
                    q.push(t + 1);
                    visited[t + 1] = true;
                }
                for (auto it : mp[arr[t]]) {
                    if (!visited[it]) {
                        visited[it] = true;
                        q.push(it);
                    }
                }
                mp.erase(arr[t]);
            }
            steps++;
        }
        return steps;
    }
};