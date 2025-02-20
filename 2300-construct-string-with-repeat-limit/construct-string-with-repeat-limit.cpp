class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        int l = s.size();
        map<char, int> mp;
        for (char c : s) {
            mp[c]++;
        }

        string ans = "";
        auto it = mp.rbegin();

        while (!mp.empty()) {
            char maxChar = it->first;
            int& maxFreq = it->second;

            if (maxFreq > repeatLimit) {
                ans.append(repeatLimit, maxChar);
                maxFreq -= repeatLimit;

                auto nextit = next(it);
                if (nextit == mp.rend()) {
                    break;
                }

                ans.push_back(nextit->first);
                nextit->second--;
                if (nextit->second == 0) {
                    mp.erase(nextit->first);
                }
            } else {
                ans.append(maxFreq, maxChar);
                mp.erase(maxChar);
            }

            it = mp.rbegin();
        }
        return ans;
    }
};