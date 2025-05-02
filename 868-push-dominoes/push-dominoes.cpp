class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.length();
        vector<int> rDist(n, INT_MAX), lDist(n, INT_MAX);

        int pVal = INT_MAX;
        // Left to right: distance from 'R'
        for (int i = 0; i < n; ++i) {
            if (dominoes[i] == 'R') pVal = 0;
            else if (dominoes[i] == 'L') pVal = INT_MAX;
            else if (pVal != INT_MAX) pVal++;
            
            rDist[i] = pVal;
        }

        pVal = INT_MAX;
        // Right to left: distance from 'L'
        for (int i = n - 1; i >= 0; --i) {
            if (dominoes[i] == 'L') pVal = 0;
            else if (dominoes[i] == 'R') pVal = INT_MAX;
            else if (pVal != INT_MAX) pVal++;
            
            lDist[i] = pVal;
        }

        string result = "";
        for (int i = 0; i < n; ++i) {
            if (dominoes[i] == 'L' || dominoes[i] == 'R') {
                result += dominoes[i];
            } else if (rDist[i] < lDist[i]) {
                result += 'R';
            } else if (lDist[i] < rDist[i]) {
                result += 'L';
            } else {
                result += '.';
            }
        }
        return result;
    }
};
