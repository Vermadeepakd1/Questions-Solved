class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        string valids = "ACGT";
        // string curr = startGene;
        int n = startGene.length();
        unordered_set<string> visited;

        queue<pair<string, int>> q;
        q.push({startGene, 0});
        visited.insert(startGene);

        while (!q.empty()) {
            auto [curr, steps] = q.front();
            q.pop();
            if (curr == endGene)
                return steps;
            for (int i = 0; i < n; i++) {
                char ch = curr[i];
                for (char nch : valids) {
                    if (ch == nch)
                        continue;
                    curr[i] = nch;
                    if (find(bank.begin(), bank.end(), curr) != bank.end() &&
                        !visited.count(curr)) {
                        q.push({curr, steps + 1});
                        visited.insert(curr);
                    }
                    curr[i] = ch;
                }
            }
        }
        return -1;
    }
};