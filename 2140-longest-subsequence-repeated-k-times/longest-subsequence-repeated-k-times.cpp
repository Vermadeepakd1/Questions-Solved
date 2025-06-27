class Solution {
public:
    bool isValid(string &pattern, string &s, int k) {
        int i = 0, count = 0;
        for (char c : s) {
            if (c == pattern[i]) {
                i++;
                if (i == pattern.size()) {
                    i = 0;
                    count++;
                }
            }
        }
        return count >= k;
    }

    string longestSubsequenceRepeatedK(string s, int k) {
        unordered_map<char, int> freq;
        for (char c : s) freq[c]++;

        string characters = "";
        for (auto &[ch, f] : freq) {
            if (f >= k) characters += ch;
        }

        sort(characters.begin(), characters.end());

        queue<string> q;
        q.push("");
        string res = "";

        while (!q.empty()) {
            string curr = q.front(); q.pop();

            for (char c : characters) {
                string next = curr + c;
                if (isValid(next, s, k)) {
                    res = next;
                    q.push(next); // explore longer ones only if current is valid
                }
            }
        }

        return res;
    }
};
