class Solution {
public:
    int totalMoney(int n) {
        int start = 28;
        int s = 0;
        int total = 0;
        while(n >= 7){
            total += start;
            s++;
            start += 7;
            n-=7;
        }
        while(n--){
            total += 1+s;
            s++;
        }
        return total;
    }
};