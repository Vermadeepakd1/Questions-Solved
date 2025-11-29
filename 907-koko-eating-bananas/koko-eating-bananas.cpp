class Solution {
    bool isPossible(vector<int>& piles, int h, int k){
        int hourstaken = 0;
        for(int i : piles){
            hourstaken +=( i + k - 1)/k;
            if(hourstaken > h)return false;
        }
        if(hourstaken > h)return false;
        return true;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(),piles.end());
        int ans = r;
        while(l < r){
            int mid = l + (r-l)/2;
            if(isPossible(piles,h,mid)){
                ans = mid;
                r = mid;
            }else{
                l = mid+1;
            }
        }

        return ans;
    }
};