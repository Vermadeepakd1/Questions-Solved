class Solution {
public:
    void solve(vector<int>& nums, int i, int size, int &cnt,int curr,int maxi){
        if(i == size){
            if(curr == maxi) {
                cnt++;
            }
            return;
        }
        // exclude
        solve(nums,i+1,size,cnt,curr,maxi);
        // include
        solve(nums,i+1,nums.size(),cnt,curr|nums[i],maxi);

    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxi = 0;
        int cnt = 0;
        for(int i =0; i<nums.size();i++){
            maxi |= nums[i];
        }
        int curr = 0;
        solve(nums,0,nums.size(),cnt,curr,maxi);
        return cnt;
    }
};