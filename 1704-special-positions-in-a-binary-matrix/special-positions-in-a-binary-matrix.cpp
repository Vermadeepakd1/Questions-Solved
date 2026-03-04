class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int cnt = 0;

        vector<int> rcount(m, 0), ccount(n, 0);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    rcount[i]++;
                    ccount[j]++;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) { 
                    if (rcount[i] == 1 && ccount[j] == 1) {
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};