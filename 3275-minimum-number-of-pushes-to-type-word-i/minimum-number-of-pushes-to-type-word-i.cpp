class Solution {
public:
    int minimumPushes(string word) {
        int c =1;
        int n = word.length();

        int ans = 0;
        while(n >8){
            ans += 8*c;
            n-=8;
            c++;
        }
        ans += n*c;
        return ans;
    }
};