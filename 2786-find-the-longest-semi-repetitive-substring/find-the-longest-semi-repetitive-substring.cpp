class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int maxi = -1;
        int n = s.length();
        for(int i = 0; i<n; i++){
            int count = 0, l = 1;
            for(int j = i+1; j<n;j++){
                if(s[j] == s[j-1]){
                    count++;
                }
                if(count == 2){
                    // maxi = max(l,maxi);
                    break;
                }
                l++;
            }
            maxi = max(l,maxi);
        }
        // if(maxi == -1){
        //     return n;
        // }
        return maxi;
    }
};