class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int maxoverlap = 0;

        for (int rowShift = -(n - 1); rowShift < n; rowShift++) {
            for (int colShift = -(n - 1); colShift < n; colShift++) {
                int cnt = 0;
                for (int r = 0; r < n; r++) {
                    for (int c = 0; c < n; c++) {
                        int nr = r + rowShift;
                        int nc = c + colShift;
                        if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                            if (img1[r][c] == 1 && img2[nr][nc] == 1) {
                                cnt++;
                            }
                        }
                    }
                }
                maxoverlap = max(maxoverlap, cnt);
            }
        }

        return maxoverlap;
    }
};