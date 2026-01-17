class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();

        if (n1 % 2 == 0 && n2 % 2 == 0)
            return 0;

        int x = 0;
        if (n1 & 1)
            for (int i : nums2)
                x ^= i;

        if (n2 & 1)
            for (int i : nums1)
                x ^= i;

        return x;
    }
};