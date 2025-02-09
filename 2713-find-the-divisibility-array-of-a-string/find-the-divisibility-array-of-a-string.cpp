class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        vector<int> result;
        long long num = 0;
        for (int i = 0; i < word.length(); i++) {
            num = (num * 10 + (word[i] - '0')) % m;
            if (num != 0) {
                result.push_back(0);
            } else {
                result.push_back(1);
            }
        }
        return result;
    }
};