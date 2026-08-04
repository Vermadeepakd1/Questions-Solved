class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mini = *min_element(nums.begin(),nums.end()), maxi = *max_element(nums.begin(),nums.end());

        vector<int> result;
        unordered_set<int>st(nums.begin(),nums.end());
        for(int i = mini; i<= maxi; i++){
            if(!st.count(i)){
                result.push_back(i);
            }
        }
        return result;
    }
};