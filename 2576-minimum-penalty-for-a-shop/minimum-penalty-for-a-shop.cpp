class Solution {
public:
    int bestClosingTime(string customers) {
        int total = 0;
        for (char& i : customers) {
            if (i == 'Y')
                total++;
        }
        int curr = 0;

        int n = customers.size();
        int mini = INT_MAX;
        int minidx = -1;
        for (int i = 0; i < n; i++) {
            int penalty = i - curr + (total - curr);
            if (mini > penalty) {
                minidx = i;
                mini = min(mini, penalty);
            }
            if (customers[i] == 'Y')
                curr++;
        }
        if(mini > n -total)minidx = n;
        return minidx;
    }
};