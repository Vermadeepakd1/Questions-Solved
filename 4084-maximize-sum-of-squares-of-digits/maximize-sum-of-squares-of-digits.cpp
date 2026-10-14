class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = "";
        for(int i = 0; i<num; i++)ans += '0';

        int i = 0;
        while(i<num && sum > 0){
            if(sum >= 9 ){
                ans[i] = '9';
                i++;
                sum -= 9;
            }else{
                ans[i] = sum + '0';
                sum = 0;
                i++;
            }
            
        }
        if(sum == 0)return ans;
        return "";
    }
};