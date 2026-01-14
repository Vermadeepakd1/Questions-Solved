class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> cnt(32,0);

        for(int i = 0; i<32; i++){
            int mask = (1<<i);

            for(int j = 0; j<candidates.size(); j++){
                if((candidates[j] & mask) != 0){
                    cnt[i]++;
                }
            }
        }
        return *max_element(cnt.begin(),cnt.end());
    }
};