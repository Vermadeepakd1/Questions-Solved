class Solution {
    void findseq(string &digits, int &k, string &temp, string &ans, vector<bool> &used) {
        if (temp.size() == digits.size()) {
            k--;
            if (k == 0) ans = temp;
            return;
        }

        for (int i = 0; i < digits.size(); i++) {
            if (!used[i]) {
                temp.push_back(digits[i]);
                used[i] = true;
                findseq(digits, k, temp, ans, used);
                used[i] = false;
                temp.pop_back();  // backtrack
                if (!ans.empty()) return;  // stop early if answer found
            }
        }
    }

public:
    string getPermutation(int n, int k) {
        string digits = "";
        for (int i = 1; i <= n; ++i) digits += to_string(i);

        string temp = "", ans = "";
        vector<bool> used(n, false);
        findseq(digits, k, temp, ans, used);
        return ans;
    }
};
