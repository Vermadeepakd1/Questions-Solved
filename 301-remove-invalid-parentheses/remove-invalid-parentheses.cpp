class Solution {
    bool isvalid(const string& s) {
        int cnt = 0;
        for (char ch : s) {
            if (ch == '(') cnt++;
            else if (ch == ')') cnt--;
            if (cnt < 0) return false;
        }
        return cnt == 0;
    }

    set<string> result;
    int reql;

    void findstrings(const string& s, int idx, string& curr, int minremove) {
        if (idx == s.length()) {
            if (minremove == 0 && curr.size() == reql && isvalid(curr)) {
                result.insert(curr);
            }
            return;
        }

        char ch = s[idx];

        if (minremove > 0 && (ch == '(' || ch == ')')) {
            findstrings(s, idx + 1, curr, minremove - 1);
        }

        curr.push_back(ch);
        findstrings(s, idx + 1, curr, minremove);
        curr.pop_back(); // Backtrack
    }

public:
    vector<string> removeInvalidParentheses(string s) {
        int minremove = 0;
        int open_cnt = 0;
        for (char ch : s) {
            if (ch == '(') open_cnt++;
            else if (ch == ')') {
                if (open_cnt > 0) open_cnt--;
                else minremove++;
            }
        }
        minremove += open_cnt;

        reql = s.length() - minremove;

        string curr = "";
        findstrings(s, 0, curr, minremove);

        return vector<string>(result.begin(), result.end());
    }
};