class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        int maxi = 0;
        for(int i = 0; i<=n-2; i++){
            int curr = 0;
            for(int j = i; j<n;j++){
                if(s[j] =='('){
                    curr++;
                }else{curr--;}

                if(curr < 0)break;

                if(curr > (n-i)/2)break;

                if(curr==0){
                    maxi = max(maxi, j-i+1);
                }
            }
        }
        return maxi;
    }
};