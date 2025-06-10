class Solution {
public:
    long long calculateScore(string s) {
        int n = s.length();
        long long score = 0;

        unordered_map<char, stack<int>> mirrorMap;
        vector<bool> marked(n, false);

        for (int i = 0; i < n; i++) {
            char mirror = 'a' + 'z' - s[i];

            while (!mirrorMap[mirror].empty() && marked[mirrorMap[mirror].top()]) {
                mirrorMap[mirror].pop();
            }

            if (!mirrorMap[mirror].empty()) {
                int j = mirrorMap[mirror].top();
                mirrorMap[mirror].pop();

                marked[i] = true;
                marked[j] = true;

                score += (i - j);
            } else {
                mirrorMap[s[i]].push(i);
            }
        }

        return score;
    }
};
