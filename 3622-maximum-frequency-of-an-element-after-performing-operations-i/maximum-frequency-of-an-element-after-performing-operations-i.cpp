class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int maxi = *max_element(nums.begin(),nums.end()) + k;

        vector<int> freq(maxi+1,0);
        for(int &i : nums){
            freq[i]++;
        }
        vector<int> cf(maxi+1,0);
        for(int i = 1; i<=maxi; i++){
            cf[i] = freq[i] + cf[i-1];
        }
        int ans = -1;
        for(int i = 0; i<=maxi; i++){
            // if(freq[i] == 0)continue;
            int l = max(i -k,0);
            int r = min(maxi,i+k);

            int total = cf[r] - (l>0 ? cf[l-1] :0);
            int targetcount = cf[i] - (i>0 ? cf[i-1] : 0);

            int needconvert = total - targetcount;

            int maxpossible = targetcount + min(needconvert,numOperations);

            ans = max(ans,maxpossible);
        }
        return ans;

    }
};