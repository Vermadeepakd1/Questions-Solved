class Solution {
public:
    int maxOperations(string s) {
        int n = s.length();
        int ans = 0;
        int ones = 0;
        for(int i = 0; i<n; i++){
            if(i == n-1 && s[i] == '0')ans += ones;
            else if(s[i] == '0' && s[i+1] == '1')ans += ones;

            if(s[i] == '1')ones++;
        }
        return ans;
    }
};