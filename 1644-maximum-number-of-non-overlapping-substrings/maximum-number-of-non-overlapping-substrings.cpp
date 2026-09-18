class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        unordered_map<char, pair<int, int>> mp;
        for (int i = 0; i < s.length(); i++) {
            if (!mp.count(s[i])) {
                mp[s[i]] = {i, i};
            } else {
                mp[s[i]].second = max(mp[s[i]].second, i);
            }
        }
        vector<pair<int, int>> store;
        for (auto it : mp) {
            int start = it.second.first;
            int end = it.second.second;
            bool isValid = true;

            for (int j = start; j <= end; j++) {
                if (mp[s[j]].first < start) {
                    isValid = false;
                    break;
                }
                end = max(end, mp[s[j]].second);
            }

            if (isValid) {
                store.push_back({start, end});
            }
        }

        sort(store.begin(), store.end(),
             [&](auto& a, auto& b) { return a.second < b.second; });

        vector<string> result;
        int end = -1;
        for (auto it : store) {
            if (it.first > end) {
                result.push_back(s.substr(it.first, it.second - it.first + 1));
                end = it.second;
            }
        }
        return result;
    }
};