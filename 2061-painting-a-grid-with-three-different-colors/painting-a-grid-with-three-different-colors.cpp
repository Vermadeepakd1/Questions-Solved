class Solution {
public:
    vector<string> columnstates;
    int mod = 1e9 + 7;
    vector<vector<int>> dp;

    void generateColumnStates(string curr, char prev, int currsize, int size) {
        if (currsize == size) {
            columnstates.push_back(curr);
            return;
        }
        for (char ch : {'R', 'G', 'B'}) {
            if (prev == ch) {
                continue;
            }
            generateColumnStates(curr + ch, ch, currsize + 1, size);
        }
    }

    int solve(int remaining, int prev, int m) {
        if (remaining == 0) {
            return 1;
        }
        if (dp[remaining][prev] != -1)
            return dp[remaining][prev];
        int ways = 0;
        string prevstate = columnstates[prev];
        for (int i = 0; i < columnstates.size(); i++) {
            if (i == prev)
                continue;

            string currstate = columnstates[i];
            bool flag = true;
            for (int j = 0; j < m; j++) {
                if (prevstate[j] == currstate[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                ways = (ways + solve(remaining - 1, i, m)) % mod;
            }
        }
        return dp[remaining][prev] = ways;
    }

    int colorTheGrid(int m, int n) {

        generateColumnStates("", '#', 0, m);

        int totalstates = columnstates.size();

        dp = vector<vector<int>>(n + 1, vector<int>(totalstates + 1, -1));
        int result = 0;
        for (int i = 0; i < totalstates; i++) {
            result = (result%mod +  solve(n - 1, i, m) % mod) % mod;
        }
        return result % mod;
    }
};