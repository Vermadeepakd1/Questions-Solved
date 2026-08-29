class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int, int>> p;
        for (int i = 0; i < n; i++) {
            p.push_back({nums[i], i});
        }
        sort(p.begin(), p.end());

        vector<int> values;
        vector<int> indices;

        int j = 0;

        while (j < n) {
            if (j == 0 || (p[j].first - p[j - 1].first <= limit) ||
                values.empty()) {
                values.push_back(p[j].first);
                indices.push_back(p[j].second);
                j++;
            } else {
                sort(indices.begin(), indices.end());
                for (int i = 0; i < indices.size(); i++) {
                    nums[indices[i]] = values[i];
                }
                values.clear();
                indices.clear();
            }
        }
        sort(indices.begin(), indices.end());
        for (int i = 0; i < indices.size(); i++) {
            nums[indices[i]] = values[i];
        }
        return nums;
    }
};