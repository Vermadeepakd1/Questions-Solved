class Solution {
    bool ispalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        return rev == s;
    }

    void solve(string& s, string temp, vector<string>& tempvec,
               vector<vector<string>>& ans, int n, int idx) {
        if (idx == n) {
            if (temp == "")
                ans.push_back(tempvec);
            return;
        }

        temp += s[idx];

        if (ispalindrome(temp)) {
            tempvec.push_back(temp);
            solve(s, "", tempvec, ans, n, idx + 1);
            tempvec.pop_back();
        }
        solve(s, temp, tempvec, ans, n, idx + 1);
    }

public:
    vector<vector<string>> partition(string s) {
        string temp = "";
        vector<vector<string>> ans;
        vector<string> tempvec;
        int n = s.length();

        solve(s, temp, tempvec, ans, n, 0);
        return ans;
    }
};