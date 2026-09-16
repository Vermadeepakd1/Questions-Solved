class Solution {
public:
    int dp[1001][1001][2];
    int mod = 1e9+7;
    int findways(int idx, int n, int lines, int k, bool started){
        if(idx == n ){
            return lines == k;
        }
        if(lines == k)return 1;
        if(dp[idx][lines][started]!=-1)return dp[idx][lines][started];
        int result = 0;
        if(started){
            //take
            result += findways(idx+1,n,lines,k,started) %mod;

            result += findways(idx,n,lines+1,k,false) %mod;
        }else{
            //skip
            result += findways(idx+1,n,lines,k,started) %mod;
            //take
            result += findways(idx+1,n,lines,k,true) %mod;
        }
        return dp[idx][lines][started]= result%mod;
    }
    int numberOfSets(int n, int k) {
        memset(dp,-1,sizeof(dp));
        return findways(0,n,0,k, false);
    }
};