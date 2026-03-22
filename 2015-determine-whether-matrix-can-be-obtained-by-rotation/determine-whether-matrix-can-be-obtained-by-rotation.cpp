int n;
class Solution {
    void rotatemat(vector<vector<int>>& mat) {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++)
                swap(mat[i][j], mat[j][i]);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n / 2; j++) {
                swap(mat[i][j], mat[i][n - j - 1]);
            }
        }
    }

public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        vector<vector<int>> rotated = mat;
        n = mat.size();
        for (int i = 0; i < 4; i++) {
            rotatemat(rotated);
            if (rotated == target)
                return true;
        }
        return false;
    }
};