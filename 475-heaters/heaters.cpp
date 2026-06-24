class Solution {
public:

    bool canHeatAll(int r, vector<int>& houses, vector<int>& heaters){
        int hsl = houses.size(), htl = heaters.size();
        int i = 0, j = 0;

        while(i < hsl && j < htl){
            if(houses[i] >= heaters[j]-r && houses[i]<=heaters[j]+r){
                i++;
            }else j++;
        }
        return i==hsl;
    }

    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int min = 0, max = 1e9;
        int ans = 1e9;
        sort(houses.begin(), houses.end());
        sort(heaters.begin(),heaters.end());
        while(min <= max){
            int mid = min+ (max-min)/2;
            if(canHeatAll(mid,houses,heaters)){
                ans = mid;
                max = mid-1;
                cout << ans <<endl;
            }else min = mid+1;
        }
        return ans;
    }
};