class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        
        vector<int> min_len(n, INT_MAX);
        
        int sum = 0, i = 0;
        int ans = INT_MAX;
        int best_so_far = INT_MAX; 

        for (int j = 0; j < n; j++) {
            sum += arr[j];

            while (sum > target) {
                sum -= arr[i];
                i++;
            }

            if (sum == target) {
                int curr_len = j - i + 1;

                if (i > 0 && min_len[i - 1] != INT_MAX) {
                    ans = min(ans, curr_len + min_len[i - 1]);
                }

                best_so_far = min(best_so_far, curr_len);
            }

            min_len[j] = best_so_far;
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
};