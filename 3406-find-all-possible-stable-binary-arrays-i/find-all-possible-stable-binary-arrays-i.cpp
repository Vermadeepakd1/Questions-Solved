class Solution {
    int mod = (1e9+7);
    int dp[201][201][2];
    int solve(int one,int zero, bool lastwasone, int limit){
        if(one == 0 && zero == 0)return 1;

        if(dp[one][zero][lastwasone]!=-1)return dp[one][zero][lastwasone];
        int result = 0;
        if(lastwasone){
            for(int i = 1; i<=min(limit,zero); i++){
                result = (result +  solve(one,zero-i,false,limit))%mod;
            }
        }else{
            for(int i = 1; i<=min(limit,one); i++){
                result= (result + solve(one-i, zero,true,limit))%mod;
            }
        }
        return dp[one][zero][lastwasone] = result%mod;
    }
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        memset(dp,-1,sizeof(dp));
        int st1 = solve(one,zero,false,limit);
        int st0 = solve(one,zero,true,limit);

        return (st1+st0)%mod;
    }
};