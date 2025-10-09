class Solution {
    bool solve(string &s, unordered_set<string> &dict, int idx, vector<int> &dp){
        if(idx == s.size()) return true;
        if (dp[idx] != -1) return dp[idx];

        for (int i = idx + 1; i <= s.size(); i++) {
            string temp = s.substr(idx, i - idx);
            if (dict.count(temp) && solve(s, dict, i, dp))
                return dp[idx] = true;
        }

        return dp[idx] = false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<int> dp(s.size(), -1);
        return solve(s, dict, 0, dp);
    }
};