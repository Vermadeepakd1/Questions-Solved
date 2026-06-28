class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int ans = 1;
        int last = 1;
        for(int i = 1; i<n ; i++){
            if(arr[i] > last){
                last++;
                ans = last;
                // cout << arr[i] << " " << ans << endl;
            }
        }
        return ans;
    }
};