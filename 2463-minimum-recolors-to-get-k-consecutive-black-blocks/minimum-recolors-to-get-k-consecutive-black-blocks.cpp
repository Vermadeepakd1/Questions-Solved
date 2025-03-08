class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.length();
        int l = 0, r = k - 1, minw = INT_MAX, w = 0;
        for (int i = 0; i <= r; i++) {
            if (blocks[i] == 'W') {
                w++;
            }
        }
        minw = w;
        r++;
        l++;
        while (r < n) {
            if (blocks[r] == 'W') {
                w++;
            }
            if (blocks[l - 1] == 'W') {
                w--;
            }
            r++, l++;
            minw = min(minw, w);
        }
        return minw;
    }
};