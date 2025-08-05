class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        vector<bool> filled(baskets.size(), false);
        int unplaced = 0;
        for(int f : fruits){
            bool placed = false;
            for(int i = 0; i< baskets.size(); i++){
                if(!filled[i]  && baskets[i] >= f){
                    filled[i] = true;
                    placed = true;
                    break;
                }
            }
            if (!placed) {
                unplaced++;
            }
        }
        return unplaced;
    }
};