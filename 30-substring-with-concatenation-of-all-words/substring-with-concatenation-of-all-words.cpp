class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if (s.empty() || words.empty()) return ans;

        int len = s.size();
        int numWords = words.size();
        int wordSize = words[0].size();
        int windowSize = wordSize * numWords;

        if (len < windowSize) return ans;

        unordered_map<string, int> freq;
        for (const string& w : words) {
            freq[w]++;
        }

        for (int start = 0; start < wordSize; start++) {
            int left = start, right = start;
            unordered_map<string, int> seen;
            int count = 0;

            while (right + wordSize <= len) {
                string word = s.substr(right, wordSize);
                right += wordSize;

                if (freq.count(word)) {
                    seen[word]++;
                    count++;

                    while (seen[word] > freq[word]) {
                        string leftWord = s.substr(left, wordSize);
                        seen[leftWord]--;
                        count--;
                        left += wordSize;
                    }

                    if (count == numWords) {
                        ans.push_back(left);
                    }
                } else {
                    seen.clear();
                    count = 0;
                    left = right;
                }
            }
        }
        return ans;
    }
};