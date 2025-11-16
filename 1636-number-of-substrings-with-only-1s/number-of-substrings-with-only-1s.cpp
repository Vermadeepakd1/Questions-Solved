class Solution {
public:
    int numSub(string s) {
        int mod =  1000000007;
        long long cont = 0;
        long long ans = 0;
        for(char c : s){
            if(c == '1'){
                cont++;
            }else{
                ans += (((cont%mod) * ((cont+1)%mod))%mod)/2;
                cont = 0;
            }
        }
        ans += (((cont%mod) * ((cont+1)%mod))%mod)/2;
        return (int)ans;
    }
};