class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int lp = players.size(), lt = trainers.size();
        int i = 0, j = 0;

        int count = 0;

        while(i < lp && j < lt){
            if(players[i] <= trainers[j]){
                count++; i++; j++;
            }else{
                j++;
            }
        }
        return count;
    }
};