class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, unordered_set<int>> rseats;
        int cnt = 0;

        for(auto &vec : reservedSeats){
            int u = vec[0],v=vec[1];
            rseats[u].insert(v);
        }

        int otherrows = n - rseats.size();

        cnt += otherrows*2;

        for(auto it: rseats){
            int row = it.first;
            unordered_set<int> booked = it.second;

            bool first = true, second = true, third  = true;

            if(booked.count(2) || booked.count(3))first = false;
            if(booked.count(5)||booked.count(4)){
                first =false;
                second = false;
            }
            if(booked.count(6)|| booked.count(7)){
                second = false;
                third = false;
            }
            if(booked.count(9)||booked.count(8))third = false;

            if(first && third)cnt +=2;
            else if(first || second || third)cnt++;
        }
        return cnt;
    }
};