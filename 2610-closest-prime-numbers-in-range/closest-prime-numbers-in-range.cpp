class Solution {
public:
    vector<bool> Sieve(int n) {
        vector<bool> prime(n + 1, true);
        prime[0] = false;
        prime[1] = false;
        for (int p = 2; p * p <= n; p++) {
            if (prime[p] == true) {
                for (int i = p * p; i <= n; i += p)
                    prime[i] = false;
            }
        }
        return prime;
    }
    vector<int> closestPrimes(int left, int right) {
        vector<bool> prime = Sieve(right);
        int last = -1, num1 = -1, num2 = -1, diff = INT_MAX;
        for (int i = left; i <= right; i++) {
            if (prime[i]) {
                if (i - last < diff) {
                    diff = i - last;
                    num1 = last;
                    num2 = i;
                }
                last = i;
            }
        }
        if (num1 == -1 || num2 == -1) {
            return {-1, -1};
        }
        return {num1, num2};
    }
};