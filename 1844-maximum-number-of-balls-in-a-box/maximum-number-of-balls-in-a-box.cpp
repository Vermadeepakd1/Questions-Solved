class Solution {
public:
    int digitsum(int num) {
        int result = 0;
        while (num > 0) {
            result += num % 10;
            num /= 10;
        }
        return result;
    }
    int countBalls(int lowLimit, int highLimit) {
        int mp[50] = {0};
        int maxi = -1;
        for (int i = lowLimit; i <= highLimit; i++) {
            int box = digitsum(i);
            mp[box]++;
            maxi = max(maxi, mp[box]);
        }
        return maxi;
    }
};