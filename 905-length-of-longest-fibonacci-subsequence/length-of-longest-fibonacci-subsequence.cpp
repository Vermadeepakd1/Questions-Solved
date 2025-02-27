class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size(), maxi = -1;
        unordered_set<int> st(arr.begin(), arr.end());
        int size = 2;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                size = 2;
                long long first = arr[i];
                long long second = arr[j];
                while (st.find(first + second) != st.end()) {
                    size++;
                    second = first + second;
                    first = second - first;
                }
                maxi = max(maxi, size);
            }
        }
        if (maxi < 3) {
            return 0;
        }
        return maxi;
    }
};