class Solution {
public:
    int missingInteger(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());
        int n = nums.size();
        int last = nums[0];
        for(int i =1; i<n; i++){
            if(nums[i] == (nums[i-1]+1)){
                last += nums[i];

            }else break;
        }

        while(st.count(last)){
            last++;
        }
        return last;
    }
};