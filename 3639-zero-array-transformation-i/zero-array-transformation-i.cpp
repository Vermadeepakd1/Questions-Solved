class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        //when you see ranges like this question, use difference array
        int n = nums.size();
        vector<int> diffarray(n+1,0);
        for(auto query : queries){
            int l = query[0], r= query[1];
            diffarray[l]++;
            diffarray[r+1]--;
        }
        for(int i = 1; i<=n ; i++){
            diffarray[i] += diffarray[i-1];
            cout << diffarray[i] << " ";
        }
        for(int i = 0; i<n; i++){
            if(nums[i] > diffarray[i]){
                return false;
            }
        }
        return true;
    }
};