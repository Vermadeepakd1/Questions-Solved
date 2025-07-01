class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.size();
        int temp = 1;
        vector<int> contNum;

        for (int i = 1; i < n; i++) {
            if (word[i] == word[i - 1]) {
                temp++;
            } else {
                contNum.push_back(temp);
                temp = 1;
            }
        }
        contNum.push_back(temp);

        int ans = 1;
        for (int num : contNum) {

            ans += (num - 1);
        }
        return ans;
    }
};