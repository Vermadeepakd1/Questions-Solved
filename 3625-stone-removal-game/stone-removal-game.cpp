class Solution {
public:
    bool canAliceWin(int n) {
        if(n < 10)return false;
        int curr = 9;
        n-=10;
        bool ans = true;
        while(n >= curr){
            n-= curr;
            ans = !ans;
            curr--;
        }
        return ans;
    }
};