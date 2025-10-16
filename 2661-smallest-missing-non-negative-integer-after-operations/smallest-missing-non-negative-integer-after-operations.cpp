class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> remainder(value, 0);
        for (long long i : nums) {
            remainder[((i % value)+value)%value]++;
        }

        int i = 0;
        while (remainder[i % value]) {
            remainder[i % value]--;
            i++;
        }
        return i;
    }
};