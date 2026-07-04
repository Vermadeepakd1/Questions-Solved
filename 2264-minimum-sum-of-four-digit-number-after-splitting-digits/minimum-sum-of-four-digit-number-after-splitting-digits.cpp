class Solution {
public:
    int minimumSum(int num) {
        string s = to_string(num);
        sort(s.begin(),s.end());
        int a = 0, b = 0;

        a += s[0]-'0';
        b+= s[1]-'0';

        a = a*10 + s[2]-'0';
        b = b*10 + s[3]-'0';

        return a+b;
    }
};