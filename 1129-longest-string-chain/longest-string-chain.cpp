class Solution {
    int dp[1001][1001];
    int n;

    bool checkPred(const string& a, const string& b) {
        if ((int)b.size() - (int)a.size() != 1)
            return false;

        int i = 0, j = 0;
        int diff = 0;

        while (i < a.size() && j < b.size()) {
            if (a[i] == b[j]) {
                i++;
                j++;
            } else {
                diff++;
                j++;
                if (diff > 1)
                    return false;
            }
        }
        return true;
    }

    int solve(vector<string>& words, int idx, int p) {

        if (idx == n)
            return 0;

        if(p!= -1 && dp[idx][p] != -1)return dp[idx][p];

        int take = 0, skip = 0;
        // take
        if (p == -1 || checkPred(words[p], words[idx])) {
            take = 1 + solve(words, idx + 1, idx);
        }

        // skip
        skip = solve(words, idx + 1, p);

        if(p!= -1)dp[idx][p] = max(take,skip);

        return max(take, skip);
    }

public:
    int longestStrChain(vector<string>& words) {
        n = words.size();
        sort(words.begin(), words.end(), [](const string& x, const string& y) {
            return x.size() < y.size();
        });
        memset(dp, -1, sizeof(dp));
        return solve(words, 0, -1);
    }
};