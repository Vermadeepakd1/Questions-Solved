class Solution {
public:
    int findMaxK(vector<int>& nums) {
        set<int> st;
        int result = -1;
        for(int i : nums){
            if(st.count(-i)){
                result = max(result,abs(i));
            }
            st.insert(i);
        }
        return result;
    }
};