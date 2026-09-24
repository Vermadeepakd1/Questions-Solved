class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> result;
        for (int i : nums) {
            auto it = lower_bound(result.begin(), result.end(), i);
            if (it == result.end())
                result.push_back(i);
            else {
                int idx = it - result.begin();
                result[idx] = i;
            }
        }
        return result.size();
    }
};