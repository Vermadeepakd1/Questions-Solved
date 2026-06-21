class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        map<int,int> mp;
        for(int i : costs)mp[i]++;
        int ans = 0;

        for(auto it: mp){
            int cst = it.first;
            int cnt = it.second;
            if(cst > coins)break;

            if(coins / cst >= cnt){
                ans += cnt;
                coins -= cnt*cst;
            }else {
                ans += coins / cst;
                break; 
            }
        }
        return ans;
    }
};