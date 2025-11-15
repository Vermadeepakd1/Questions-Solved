class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans = 0;
        int ones = 0;
        int n = s.size();
        int zeros;
        vector<int> prefixsum(n+1,0);
        for(int i = 0; i<n; i++){
            prefixsum[i+1] = prefixsum[i] + (s[i]-'0');
        }
        for(int i = 0; i<n; i++){
            for(int j = i; j<n; j++){
                ones = prefixsum[j+1] - prefixsum[i];

                zeros = j-i+1-ones;

                if(zeros * zeros  > ones){
                    int jump = zeros*zeros - ones;
                    j += jump-1;
                }else if(zeros * zeros == ones){
                    ans += 1;
                }else{
                    ans += 1;
                    int jump = sqrt(ones) - zeros;
                    if(j+jump >= n){
                        ans += (n-j-1);
                        break;
                    }else{
                        ans += jump;
                    }
                    j+=jump;
                }
            }
        }
        return ans;
    }
};