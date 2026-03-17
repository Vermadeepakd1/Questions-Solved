class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int result = 0;
        vector<int> heights(n, 0);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1) {
                    heights[j]++;
                } else {
                    heights[j] = 0;
                }
            }

            vector<int> sortedHeights = heights;
            sort(sortedHeights.begin(), sortedHeights.end(), greater<int>());

            for (int k = 0; k < n; k++) {
                if (sortedHeights[k] == 0) break; 
                result = max(result, (k + 1) * sortedHeights[k]);
            }
        }
        return result;
    }
};