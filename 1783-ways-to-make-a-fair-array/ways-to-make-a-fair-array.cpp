class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        vector<int> evensuffix(n, 0), oddsuffix(n, 0);
        int evensum = 0, oddsum = 0;
        for (int i = n - 1; i >= 0; i--) {
            oddsuffix[i] = oddsum;
            evensuffix[i] = evensum;
            if (i & 1) {
                oddsum += nums[i];
            } else {
                evensum += nums[i];
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int ceven = evensum, codd = oddsum;
            int preveven = 0, prevodd = 0;

            if (i & 1) {
                codd -= nums[i];
                prevodd = oddsum - nums[i] - oddsuffix[i];
                preveven = evensum - evensuffix[i];
            } else {
                ceven -= nums[i];
                prevodd = oddsum  - oddsuffix[i];
                preveven = evensum - nums[i] - evensuffix[i];
            }

            if(preveven + oddsuffix[i] == prevodd + evensuffix[i])cnt++;
        }
        return cnt;
    }
};