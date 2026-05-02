class Solution {
    bool isvalid(int n) {
        int diff = 0, same = 0, invalid=0;
        while (n != 0) {
            int rem = n % 10;
            if (rem == 2 || rem == 5 || rem == 6 || rem == 9) {
                diff++;
            }else if(rem == 0 || rem == 1 || rem==8){
                same++;
            }else invalid++;
            n /= 10;
        }
        if(diff == 0 || invalid!=0)return false;
        return true;
    }

public:
    int rotatedDigits(int n) {
        // 2 5 6 9
        int cnt = 0;
        for (int i = 2; i <= n; i++) {
            if (isvalid(i))
                cnt++;
        }
        return cnt;
    }
};