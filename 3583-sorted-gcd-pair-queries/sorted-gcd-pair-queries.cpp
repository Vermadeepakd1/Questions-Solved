class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int maxi = *max_element(nums.begin(),nums.end());

        vector<long long> freq(maxi+1, 0);
        for(int i : nums)freq[i]++;

        vector<long long> divcnt(maxi+1,0);

        for(int g = 1; g <= maxi; g++){
            for(int x = g; x<=maxi; x+=g){
                divcnt[g] += freq[x];
            }
        }

        vector<long long> exact(maxi + 1, 0);

        for(int g = maxi; g >= 1; g--){
            exact[g] = divcnt[g]*(divcnt[g]-1)/2;

            for(int m = 2*g; m<=maxi; m+=g){
                exact[g] -= exact[m];
            }
        }

        vector<long long> prefix(maxi+1,0);
        for(int i = 1; i<=maxi; i++){
            prefix[i] = prefix[i-1] + exact[i];
        }

        vector<int> ans;

        for(long long q : queries){
            int g = lower_bound(prefix.begin()+1, prefix.end(),q+1) - prefix.begin();
            ans.push_back(g);
        }
        return ans;



    }
};