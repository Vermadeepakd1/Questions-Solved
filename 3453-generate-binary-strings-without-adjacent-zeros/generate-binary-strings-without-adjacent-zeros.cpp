class Solution
{
    public:
        void solve(int prev, int &n, string &curr, vector<string> &ans)
        {
            if (curr.length() == n)
            {
                ans.push_back(curr);
                return;
            }
            if (prev == -1 || prev == 1)
            {
                curr += '0';
                solve(0, n, curr, ans);
                curr.pop_back();
            }
            curr += '1';
            solve(1, n, curr, ans);
            curr.pop_back();
            return;
        }
    vector<string> validStrings(int n)
    {
        string s = "";
        vector<string> ans;
        solve(-1, n, s, ans);
        return ans;
    }
};