class Solution {
public:
    int mod = 1e9+7;
    int distinctSubseqII(string s) {
        int n = s.length();
        unordered_map<char,int> mp;
        vector<long long> dp(n+1,0);
        for(int i = 1; i<=s.length(); i++){
            if(mp.count(s[i-1])){
                int rep = dp[mp[s[i-1]]] % mod;
                dp[i] = (dp[i-1]*2 - rep + mod)%mod ;
            }else{
                dp[i] =( dp[i-1]*2 +1)%mod;
            }
            mp[s[i-1]]=i-1;
        }
        return dp[n];
    }
};