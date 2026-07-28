class Solution {
    bool isvalid(vector<int>& weights, int days, int m){
        int cnt = 1;
        int curr = 0;

        for(int i : weights){
            if(i > m)return false;
            if(curr + i <= m){
                curr += i;
            }else{
                cnt++;
                curr = i;
            }
            if(cnt > days)return false;
        }
        return true;
        
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int s = *min_element(weights.begin(),weights.end()), e = accumulate(weights.begin(),weights.end(),0);

        int ans = e;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(isvalid(weights,days,mid)){
                ans = mid;
                e = mid-1;
            }else s = mid+1;
        }
        return ans;
    }
};