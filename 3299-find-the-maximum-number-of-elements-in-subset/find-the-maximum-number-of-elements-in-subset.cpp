class Solution {
public:
    int findlen(long long val, unordered_map<int, int>& mp) {
        int ans = 0;
        while(mp.find(val) != mp.end() && mp[val] > 0) {
            if(mp[val] > 1) {
                ans += 2;
            } else {
                ans++;
                break;
            }
            
            val *= val; 
            if(val > 1e9) break; 
        }

        if(ans % 2 == 0) ans--;
        
        return ans;
    }
    int maximumLength(vector<int>& nums) {
        unordered_map<int,int> mp;

        for(int i : nums)mp[i]++;
        int ans = 1;
        for(auto &[val,cnt]:mp){
            if(val == 1){
                if(cnt%2==0)cnt--;
                ans = max(ans,cnt);
            }else if(cnt > 1){
                int len = findlen(val, mp);
                ans = max(ans,len);
            }
        }
        return ans;
    }
};