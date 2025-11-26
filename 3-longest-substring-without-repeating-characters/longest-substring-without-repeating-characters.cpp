class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int n = s.size();
        int right = 0, left = 0;
        int maxlen = 0;
        while (right < n) {
            while(st.find(s[right]) != st.end() ){
                st.erase(s[left]);
                left++;
            }
            st.insert(s[right]);
            maxlen = max(maxlen, right - left + 1);
            right++;
        }
        return maxlen;
    }
};
