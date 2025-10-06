class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        vector<bool> visited(n, false);

        for (int i = 0; i < n; ++i) {
            if (visited[i]) continue;
            int target;

            if (arr[i] < 0) {
                if (arr[i] % 2 != 0) return false;
                target = arr[i] / 2;
            } else {
                target = arr[i] * 2;
            }

            bool found = false;
            for (int j = i + 1; j < n; ++j) {
                if (!visited[j] && arr[j] == target) {
                    visited[i] = visited[j] = true;
                    found = true;
                    break;
                }
            }

            if (!found) return false;
        }

        return true;
    }
};
