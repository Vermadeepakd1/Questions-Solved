class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        string ans = "";
        int cnt1 = 0;
        int i = 0;

        for (int j = 0; j < n; j++) {
            if (s[j] == '1') cnt1++;

            while (cnt1 > k || (i <= j && cnt1 == k && s[i] == '0')) {
                if (s[i] == '1') cnt1--;
                i++;
            }

            if (cnt1 == k) {
                string ns = s.substr(i, j - i + 1);
                if (ans == "" || ns.length() < ans.length() || 
                   (ns.length() == ans.length() && ns < ans)) {
                    ans = ns;
                }
            }
        }
        return ans;
    }
};