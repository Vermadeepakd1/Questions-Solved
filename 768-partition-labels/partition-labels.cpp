class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();
        vector<int> result;
        unordered_map<char, int> mp;
        for (int i = 0; i < n; i++) {
            mp[s[i]] = i;
        }
        int st = 0, e = mp[s[0]];
        while (e < n) {
            for (int i = st; i <= e; i++) {
                if (mp[s[i]] > e) {
                    e = mp[s[i]];
                }
            }
            result.push_back(e - st + 1);
            st = e + 1;
            if (st < n) {
                e = mp[s[st]];
            } else {
                break;
            }
        }
        return result;
    }
};