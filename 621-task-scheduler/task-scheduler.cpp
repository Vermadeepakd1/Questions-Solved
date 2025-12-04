class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        unordered_map<int, int> mp;

        for (char c : tasks) {
            mp[c]++;
        }

        for (auto it : mp) {
            pq.push(it.second);
        }
        int result = 0;

        while (!pq.empty()) {
            vector<int> temp;
            for (int i = 0; i <= n && !pq.empty(); i++) {
                temp.push_back(pq.top() - 1);
                pq.pop();
            }
            int t = temp.size();
            for (int i : temp) {
                if (i != 0)
                    pq.push(i);
            }
            if (!pq.empty())
                result += (n + 1);
            else
                result += t;
        }
        return result;
    }
};