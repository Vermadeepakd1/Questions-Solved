class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        priority_queue<int, vector<int>, greater<int>> ph, th;
        for(int i : players) ph.push(i);
        for(int i : trainers) th.push(i);
        int count = 0;
        while(!ph.empty() && !th.empty()){
            int pfront = ph.top();
            int tfront = th.top();

            if(pfront <= tfront){
                ph.pop(); th.pop(); count++;
            }else{
                th.pop();
            }
        }
        return count;
    }
};