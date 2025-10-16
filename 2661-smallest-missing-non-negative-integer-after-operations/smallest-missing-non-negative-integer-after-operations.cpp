class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<long long> remainder(value, 0);
        for (long long i : nums) {
            remainder[((i % value)+value)%value]++;
        }

        long long i = 0;
        while (remainder[i % value]) {
            remainder[i % value]--;
            i++;
        }
        return (int)i;
    }
};