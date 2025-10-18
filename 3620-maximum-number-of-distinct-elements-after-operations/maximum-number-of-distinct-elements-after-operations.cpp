class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        unordered_set<int> st;
        int cnt =0 ;
        int mini = *min_element(nums.begin(),nums.end())-k;
        for(int i : nums){
            if(mini >= i-k && mini <= i+k){
                cnt++;
                mini++;
            }else if(i-k > mini){
                mini = i-k+1;
                cnt++;
            }
        }
        return cnt;
    }
};