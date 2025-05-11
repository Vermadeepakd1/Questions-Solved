class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int cnt = 0;
        for(int a : arr){
            if(a % 2){
                cnt++;
            } else{
                cnt = 0;
            }
            if(cnt == 3){
                return true;
            }
        }
        return false;
    }
};