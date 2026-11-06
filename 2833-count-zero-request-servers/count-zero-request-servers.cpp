class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x,
                             vector<int>& queries) {
        vector<pair<int, int>> sortedQueries;
        for (int i = 0; i < queries.size(); i++) {
            sortedQueries.push_back({queries[i], i});
        }

        sort(logs.begin(), logs.end(),
             [&](auto& a, auto& b) { return a[1] < b[1]; });
        sort(sortedQueries.begin(), sortedQueries.end(),
             [&](auto& a, auto& b) { return a.first < b.first; });

        vector<int> ans(queries.size(), 0);
        unordered_map<int, int> mp;
        
        int j = 0;  
        int i = 0;  
        int ll = logs.size();

        for (auto& q : sortedQueries) {
            int queryTime = q.first;
            int originalIdx = q.second;

            while (j < ll && logs[j][1] <= queryTime) {
                mp[logs[j][0]]++;
                j++;
            }

            while (i < ll && logs[i][1] < queryTime - x) {
                int s = logs[i][0];
                mp[s]--;
                if (mp[s] == 0)
                    mp.erase(s);
                i++;
            }

            ans[originalIdx] = n - mp.size();
        }

        return ans;
    }
};
