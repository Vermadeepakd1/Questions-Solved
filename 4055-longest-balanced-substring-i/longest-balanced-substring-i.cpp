class Solution {
public:
    int longestBalanced(string s) {
        int ans = 1;
        for (int i = 0; i < s.length(); i++) {
            unordered_map<char, int> mp;
            int mini = INT_MAX;
            int maxi = INT_MIN;
            for (int j = i; j < s.length(); j++) {
                mp[s[j]]++;
                int minKey, maxKey;
                int minValue = INT_MAX;
                int maxValue = INT_MIN;

                for (auto& [key, value] : mp) {
                    if (value < minValue) {
                        minValue = value;
                        minKey = key;
                    }
                    if (value > maxValue) {
                        maxValue = value;
                        maxKey = key;
                    }
                }

                if (minValue == maxValue) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};