class Solution {
    vector<int> dp;
    int solve(vector<int>& stoneValue, int idx){
        if(idx == stoneValue.size())return 0;
        if(dp[idx] != -4000)return dp[idx];
        int sum = 0;
        int result = -4000;
        for(int i = 0; i<min(3,((int)stoneValue.size()-idx)); i++){
            sum += stoneValue[idx+i];
            result = max(result, sum-solve(stoneValue,idx+i+1));
        }
        return dp[idx] = result;
    }
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        dp.assign(n+1,-4000);
        int diff = solve(stoneValue,0);
        if(diff >0)return "Alice";
        else if(diff <0)return "Bob";
        return "Tie";
    }
};