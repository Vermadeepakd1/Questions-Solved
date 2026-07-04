class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        mp[0]=-1;
        int n = nums.size();
        int sum = 0;
        int allowed = -1;
        int cnt = 0;
        for(int i = 0; i<n; i++){
            sum += nums[i];
            cout << "sum" << sum << endl;
            if(mp.count(sum-target) && mp[sum-target] >= allowed){
                cout << sum << " " << mp[sum-target] << " " << allowed << endl;
                allowed = i;
                cnt++;
            }
            mp[sum] = i;
        }
        return cnt;
    }
};