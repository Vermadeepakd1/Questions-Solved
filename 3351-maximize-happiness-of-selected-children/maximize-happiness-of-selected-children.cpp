class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n = happiness.size();
        sort(happiness.begin(),happiness.end());
        long long score = 0;
        for(int i = 0; i<k; i++){
            score += max(1LL *happiness[n-i-1] - (i),0LL);
        }
        return score;
    }
};