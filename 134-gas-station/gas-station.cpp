class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0;
        int tank = 0;
        int n = gas.size();
        int need = 0;

        for(int i = 0; i<n; i++){
            tank = tank + gas[i]-cost[i];
            if(tank < 0){
                start = i+1;
                need += -tank;
                tank = 0;
            }
        }
        if(tank >= need && start <n)return start;
        return -1;
    }
};