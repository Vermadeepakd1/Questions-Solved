class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxi = *max_element(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> check(n,0);
        for(int i = 0; i<n; i++){
            if(nums[i] == maxi){
                check[i] = 1;
            }
        }
        long long result = 0;
        int start = 0 ,end = 0,cnt = 0;
        for(int start = 0; start<n; start++){
            if (start > 0) cnt -= check[start - 1];
            while(end < n && cnt < k){
                cnt += check[end];
                end++;
            }
            if(cnt == k){
                result += (n - end + 1);
            }
        }
        return result;
    }
};