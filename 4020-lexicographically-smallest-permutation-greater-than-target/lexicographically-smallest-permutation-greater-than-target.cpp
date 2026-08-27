class Solution {
public:
    bool makeans(string &ans, vector<int>& cnt, int idx, const string &target, bool sortnow) {
        if (idx == target.size()) {
            return sortnow; 
        }

        if (sortnow) {
            for (int c = 0; c < 26; c++) {
                if (cnt[c] > 0) {
                    ans.push_back(c + 'a');
                    cnt[c]--;
                    if (makeans(ans, cnt, idx + 1, target, true)) return true;
                    cnt[c]++;
                    ans.pop_back();
                }
            }
            return false;
        }

        int ch = target[idx] - 'a';

        if (cnt[ch] > 0) {
            ans.push_back(ch + 'a');
            cnt[ch]--;
            if (makeans(ans, cnt, idx + 1, target, false)) return true;
            cnt[ch]++;
            ans.pop_back();
        }

        for (int c = ch + 1; c < 26; c++) {
            if (cnt[c] > 0) {
                ans.push_back(c + 'a');
                cnt[c]--;
                if (makeans(ans, cnt, idx + 1, target, true)) return true;
                cnt[c]++;
                ans.pop_back();
            }
        }

        return false;
    }

    string lexGreaterPermutation(string s, string target) {
        vector<int> cnt(26, 0);
        for (char ch : s) cnt[ch - 'a']++;

        string ans = "";
        if (makeans(ans, cnt, 0, target, false)) {
            return ans;
        }

        return "";
    }
};