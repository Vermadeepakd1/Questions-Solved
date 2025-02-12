class Solution {
public:
    int digitsum(int num) {
        int sum = 0;
        while (num != 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        int maxi = -1;
        int n = nums.size();
        unordered_map<int, int> digitSumMap;
        for (int num : nums) {
            int dsum = digitsum(num);
            if (digitSumMap.count(dsum)) {
                maxi = max(maxi, digitSumMap[dsum] + num);
                digitSumMap[dsum] = max(digitSumMap[dsum], num);
            } else {
                digitSumMap[dsum] = num;
            }
        }
        return maxi;
    }
};