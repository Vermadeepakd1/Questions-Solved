class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size(), m = tasks.size();
        
        // free_servers: {weight, index} 
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> free_servers;
        // busy_servers: {free_time, weight, index}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> busy_servers;

        for (int i = 0; i < n; i++) {
            free_servers.push({servers[i], i});
        }

        vector<int> ans(m, 0);
        long long current_time = 0;

        for (int j = 0; j < m; j++) {
            current_time = max(current_time, (long long)j);

            while (!busy_servers.empty() && busy_servers.top()[0] <= current_time) {
                auto b = busy_servers.top();
                busy_servers.pop();
                free_servers.push({b[1], b[2]}); // {weight, index}
            }

            if (free_servers.empty()) {
                current_time = busy_servers.top()[0];
                while (!busy_servers.empty() && busy_servers.top()[0] <= current_time) {
                    auto b = busy_servers.top();
                    busy_servers.pop();
                    free_servers.push({b[1], b[2]});
                }
            }

            auto s = free_servers.top();
            free_servers.pop();

            int weight = s[0];
            int index = s[1];

            ans[j] = index;
            busy_servers.push({(int)(current_time + tasks[j]), weight, index});
        }

        return ans;
    }
};