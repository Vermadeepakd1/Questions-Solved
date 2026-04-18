class Solution {
    int rever(int n){
        string s = to_string(n);
        reverse(s.begin(),s.end());
        return stoi(s);
    }
public:
    int mirrorDistance(int n) {
        return abs(n-rever(n));
    }
};