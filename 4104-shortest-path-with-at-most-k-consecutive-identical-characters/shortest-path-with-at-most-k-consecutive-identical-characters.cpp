class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (const auto &vec : edges) {
            int u = vec[0], v = vec[1], w = vec[2];
            adj[u].push_back({v, w});
        }

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq; 

        int stride_char = k + 1;
        int stride_node = 26 * stride_char;
        vector<int> dist(n * stride_node, 1e9);

        int start_char = labels[0] - 'a';
        int start_idx = 0 * stride_node + start_char * stride_char + 1;
        dist[start_idx] = 0;
        pq.push({0, 0, start_char, 1});

        while (!pq.empty()) {
            auto curr_state = pq.top();
            pq.pop();

            int wt = curr_state[0];
            int node = curr_state[1];
            int lchar = curr_state[2];
            int con = curr_state[3];

            if (node == n - 1) return wt;

            int curr_idx = node * stride_node + lchar * stride_char + con;
            if (wt > dist[curr_idx]) continue;

            for (const auto &edge : adj[node]) {
                int next_node = edge.first;
                int weight = edge.second;
                int next_char = labels[next_node] - 'a';
                
                int new_con = (lchar == next_char) ? con + 1 : 1;

                if (new_con <= k) {
                    int next_idx = next_node * stride_node + next_char * stride_char + new_con;
                    if (wt + weight < dist[next_idx]) {
                        dist[next_idx] = wt + weight;
                        pq.push({wt + weight, next_node, next_char, new_con});
                    }
                }
            }
        }
        return -1;
    }
};
