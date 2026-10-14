class Solution {
public:
    string predictPartyVictory(string senate) {
        int r = 0, d = 0;
        queue<char> q;
        for (char ch : senate) {
            q.push(ch);
        }
        bool hasR = true, hasD = true;
        while (hasR && hasD) {
            if (q.size() == r || q.size() == d)
                break;
            int x = q.size();
            hasR = false;
            hasD = false;
            for (int i = 0; i < x; i++) {
                char ch = q.front();
                q.pop();
                if (ch == 'R') {
                    if (d == 0) {
                        r++;
                        hasR = true;
                        q.push(ch);
                    } else
                        d--;
                } else {
                    if (r == 0) {
                        d++;
                        hasD = true;
                        q.push(ch);
                    } else
                        r--;
                }
            }
        }
        return hasR ? "Radiant" : "Dire";
    }
};