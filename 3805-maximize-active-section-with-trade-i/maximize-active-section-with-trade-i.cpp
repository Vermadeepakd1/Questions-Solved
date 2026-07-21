class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int curractive = 0;
        int curr = 0, prev = 0, prevprev = 0;
        char currch = ',';
        for (char& ch : s)
            if (ch == '1')
                curractive++;

        int maxi = curractive;
        int old = curractive;

        for (char& ch : s) {
            if (ch == currch) {
                curr++;
            } else {
                currch = ch;
                prevprev = prev;
                prev = curr;
                curr = 1;
            }

            // cout << ch << " " << prevprev << " " << prev << " " << curr << " "
            //      << endl;

            if (ch == '0' && prev!=0 && prevprev!=0) {
                int pos = curractive  +prevprev + curr;
                maxi = max(maxi, pos);
            }
        }
        return maxi;
    }
};