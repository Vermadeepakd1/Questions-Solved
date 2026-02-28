class Solution {
    int mod = 1e9+7;
    string dectobin(int n){
        string ans = "";
        while(n!=0){
            ans += (n%2)+'0';
            n/=2;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
public:
    int concatenatedBinary(int n) {
        long long  result = 0;
        for(int i = 1; i<=n; i++){
            string num = dectobin(i);
            for(int j = 0; j<num.length(); j++){
                result = ((result%mod * 2)%mod + (num[j]-'0'))%mod ;
            }
        }
        return (int)result;
    }
};