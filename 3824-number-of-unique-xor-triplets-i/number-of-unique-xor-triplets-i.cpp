class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2)
            return n;
        int next2 = 1;
        while (next2 <= n)
            next2 <<= 1;
        return next2;
    }
};