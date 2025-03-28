class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size(), m = potions.size();
        sort(potions.begin(),potions.end());
        vector<int> pairs(n);

        for(int i = 0; i<n; i++){
            long long minpotion = (success + spells[i] - 1) / spells[i];
            int index = lower_bound(potions.begin(), potions.end(),minpotion) - potions.begin();
            pairs[i] = m -index;
        }
        return pairs;
    }
};