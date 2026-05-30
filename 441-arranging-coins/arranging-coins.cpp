class Solution {
public:
    int arrangeCoins(int n) {
        long long right = 1e5;
        long long left = 0;
        long long ans = 0;

        while(left <= right){
            long long mid = left + (right-left)/2;
            if(1ll*(mid*(mid+1))/2 > n){
                right = mid-1;
            }else{
                ans = mid;
                left = mid+1;
            }
        }
        return (int)ans;
    }
};