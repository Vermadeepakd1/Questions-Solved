class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int l = 0,r = k-1,n = arr.size(),sum = 0,count = 0;
        for(int i = l; i<=r; i++){
            sum += arr[i];
        }
        if(sum/k >= threshold){
            count++;
        }
        while(r<n){
            sum -= arr[l];
            l++,r++;
            if(r >= n){
                break;
            }
            sum += arr[r];
            if(sum/k >= threshold){
            count++;
        }
        }
        return count;
    }
};