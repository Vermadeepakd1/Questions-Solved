class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        int first = nums[0];
        set<pair<int, int>> st, rem;
        long long minsum = LLONG_MAX;
        long long curr = 0;
        int i = 1, j = 1;
        while (j < n) {
            while (j - i > dist) {
                if (st.find({nums[i], i}) != st.end()) {
                    st.erase({nums[i], i});
                    curr -= nums[i];

                } else {
                    rem.erase({nums[i], i});
                }
                i++;
            }
            rem.insert({nums[j], j});
            // curr += nums[j];
            while (st.size() < k - 1 && rem.size() > 0) {
                auto pr = *rem.begin();
                st.insert(pr);
                rem.erase(pr);
                curr += pr.first;
            }

            if (st.size() == k - 1 && !rem.empty() &&
                st.rbegin()->first > rem.begin()->first) {
                auto p1 = *st.rbegin();
                auto p2 = *rem.begin();

                curr = curr - p1.first + p2.first;

                st.erase(prev(st.end()));
                rem.erase(rem.begin());

                st.insert(p2);
                rem.insert(p1);
            }
            if (st.size() == k - 1) {

                minsum = min(minsum, curr);
            }
            j++;
        }
        return minsum + first;
    }
};