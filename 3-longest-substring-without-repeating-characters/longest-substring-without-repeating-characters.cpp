class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int n = s.size();
        int right = 0, left = 0;
        int maxlen = 0;
        while (right < n) {
            while (right < n && st.find(s[right]) == st.end()) {
                st.insert(s[right]);
                right++;
            }

            maxlen = max(maxlen, right - left);

            while (s[left] != s[right]) {
                st.erase(s[left]);
                left++;
            }
            st.erase(s[left]);
            left++;
        }
        return maxlen;
    }
};
