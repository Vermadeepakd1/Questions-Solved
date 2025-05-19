class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        unordered_set<int> st;
        for(int num : nums){
            st.insert(num);
        }
        int len = 1;
        for(auto it : st){
            int temp = 0;
            if(st.find(it - 1) == st.end()){
                int curr = it;
                while(st.find(curr) != st.end()){
                temp++;
                curr++;
                }
            }
            len = max(len,temp);
        }
        return len;
    }
};