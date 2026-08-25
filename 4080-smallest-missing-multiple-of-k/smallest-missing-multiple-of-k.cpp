class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        set<int> st(nums.begin(),nums.end());
        for(int i =1; i*k <= 200; i++){
            if(!st.count(i*k))return i*k;
        }
        return -1;
    }
};