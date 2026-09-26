class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;
        for (auto& v : knowledge) {
            mp[v[0]]= v[1];
        }
        string ans = "";
        string curr = "";
        bool start = false;
        for (char ch : s) {
            if (ch == '(')
                start = true;
            else if (ch == ')') {
                start = false;
                if (mp.count(curr)) {
                    ans += mp[curr];
                } else
                    ans += "?";
                curr = "";
            } else {
                if (start)
                    curr += ch;
                else
                    ans += ch;
            }
        }
        if (curr != "") {
            if (mp.count(curr)) {
                ans += mp[curr];
            } else
                ans += "?";
        }
        return ans;
    }
};