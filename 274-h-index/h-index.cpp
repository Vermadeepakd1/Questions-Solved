class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();

        sort(citations.begin(),citations.end());
        int s = 0, e = n;

        int ans = s;
        while(s <= e){
            int mid = s + (e-s)/2;
            int idx = lower_bound(citations.begin(),citations.end(),mid) - citations.begin();
            int num = n - idx;

            if(num >= mid){
               ans = mid;
                s= mid+1;
            }else e = mid-1;
            
        }
        return ans;
    }
};