class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int ans = 0;
        int sz = flowerbed.size();

        if(sz == 0){
            if(n ==0 )return true;
            return false;
        }

        if(n == 0)return true;
        if(sz == 1){
            if(flowerbed[0] == 0 && n <= 1)return true;
            return false;
        }
        
        for (int i = 0; i < sz; i++) {
            if (flowerbed[i] == 0) {
                if ( i == 0 ) {
                    if(flowerbed[i + 1] == 0){
                    ans++;
                    flowerbed[i] = 1;}

                } else if ( i == sz - 1) {
                    if(sz >2  && flowerbed[i - 1] == 0 ){

                    ans++;
                    flowerbed[i] = 1;
                    }
                } else if (flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0) {
                    ans++;
                    flowerbed[i] = 1;
                }
            }
        }
        
        cout << ans << endl;
        return ans >= n;
    }
};