class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = 0;
        int rem = 0;

        int filled = numBottles, empty = 0;
        while (filled + empty >= numExchange || filled > 0) {
            ans += filled;
            empty += filled;
            filled = empty / numExchange;
            empty = empty % numExchange;
        }
        return ans;
    }
};