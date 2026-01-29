class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original,
                          vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>> dist(26, vector<long long>(26, 1e9));
        for (int i = 0; i < original.size(); i++) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            long long c = cost[i];

            dist[u][v] = min(dist[u][v], c);
        }

        // floydd warshall
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    if (i == j) {
                        dist[i][j] = 0;
                        continue;
                    }
                    if (dist[i][k] != 1e9 && dist[k][j] != 1e9) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        long long result = 0;
        for (int i = 0; i < source.length(); i++) {
            int u = source[i] - 'a';
            int v = target[i] - 'a';
            long long c = dist[u][v];

            if (c >= 1e9)
                return -1;
            result += c;
        }
        return result;
    }
};