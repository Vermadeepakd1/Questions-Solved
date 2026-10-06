class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits,
                             vector<int>& capital) {
        vector<pair<int, int>> cp;
        int n = profits.size();

        for (int i = 0; i < n; i++) {
            cp.push_back({capital[i], profits[i]});
        }
        sort(cp.begin(), cp.end());

        priority_queue<pair<int, int>> pq; // profit,capital

        int i = 0;
        while (i < n && cp[i].first <= w) {
            cout << "dsds" << endl;

            pq.push({cp[i].second, cp[i].first});
            i++;
        }

        while (!pq.empty() && k) {
            cout << "dsds" << endl;
            auto [p, c] = pq.top();
            pq.pop();

            w += p;
            k--;

            while (i < n && cp[i].first <= w) {
                pq.push({cp[i].second, cp[i].first});
                i++;
            }
        }
        return w;
    }
};