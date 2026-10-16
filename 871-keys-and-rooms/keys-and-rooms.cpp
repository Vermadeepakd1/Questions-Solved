class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> visited(n, false);
        visited[0] = true;
        queue<int> q;
        q.push(0);

        while (!q.empty()) {
            int x = q.front();
            q.pop();

            for (int i : rooms[x]) {
                if (!visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }

        for (int i = 0; i < n; i++)
            if (!visited[i])
                return false;
        return true;
    }
};