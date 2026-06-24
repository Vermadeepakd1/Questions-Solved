class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int absdiff = 0;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            absdiff += abs(nums[0]-nums[i]);
        }
        vector<int> result(n,0);
        result[0] = absdiff;
        for(int i = 1; i<n; i++){
            int prevcnt = i-1;
            int nextcnt = n-i-1;
            int diff = nums[i]-nums[i-1];

            // cout << prevcnt << " " << nextcnt << " " << diff << endl;
            result[i] =( result[i-1]+ diff*prevcnt - diff*nextcnt);
        }
        return result;
    }
};