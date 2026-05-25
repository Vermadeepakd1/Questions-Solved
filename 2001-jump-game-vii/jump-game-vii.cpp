class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        if (s[n - 1] == '1') return false; 

        vector<int> diffarr(n + 1, 0); 
        int count = 0;

        for (int i = 0; i < n; i++) {
            count += diffarr[i];

            if (i == 0 || (s[i] == '0' && count > 0)) {

                if (i == n - 1) return true;

                int left_bound = i + minJump;
                int right_bound = i + maxJump;

                if (left_bound < n) {
                    diffarr[left_bound] += 1;

                    int upper_limit = min(right_bound + 1, n);
                    diffarr[upper_limit] -= 1;
                }
            }
        }

        return false;
    }
};