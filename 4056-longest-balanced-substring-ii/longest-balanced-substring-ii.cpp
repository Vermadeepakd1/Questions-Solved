class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();
        int maxlen = 0;

        int curr = 0;
        for (int i = 0; i < n; i++) {
            if (i > 0 && s[i] == s[i - 1]) curr++;
            else curr = 1;
            maxlen = max(maxlen, curr);
        }

        auto solveTwo = [&](char x, char y, char forbidden) {
            map<int, int> mp;
            mp[0] = -1; 
            int balance = 0;
            for (int i = 0; i < n; i++) {
                if (s[i] == forbidden) {
                    mp.clear();
                    mp[0] = i;
                    balance = 0;
                } else {
                    if (s[i] == x) balance++;
                    if (s[i] == y) balance--;
                    if (mp.count(balance)) maxlen = max(maxlen, i - mp[balance]);
                    else mp[balance] = i;
                }
            }
        };

        solveTwo('a', 'b', 'c');
        solveTwo('b', 'c', 'a');
        solveTwo('a', 'c', 'b');

        map<pair<int, int>, int> abc;
        abc[{0, 0}] = -1;
        int a = 0, b = 0, c = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') a++;
            else if (s[i] == 'b') b++;
            else c++;

            pair<int, int> state = {a - b, b - c};
            if (abc.count(state)) maxlen = max(maxlen, i - abc[state]);
            else abc[state] = i;
        }

        return maxlen;
    }
};