class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        stack<pair<int, int>> st; 
        int n = positions.size();
        vector<pair<int, pair<char, int>>> p;

        for (int i = 0; i < n; i++) {
            p.push_back({positions[i], {directions[i], healths[i]}});
        }
        
        sort(p.begin(), p.end());
        unordered_map<int, int> mp;

        for (auto &bp : p) {
            int pos = bp.first;
            char dir = bp.second.first;
            int h = bp.second.second;

            if (dir == 'L') {
                bool destroyed = false;
                while (!st.empty() && h > 0) { 
                    if (st.top().second < h) {
                        st.pop();
                        h--;
                    } else if (st.top().second > h) {
                        st.top().second--; 
                        h = 0;
                        destroyed = true;
                    } else {
                        st.pop();
                        h = 0;
                        destroyed = true;
                    }
                }
                if (!destroyed) mp[pos] = h;
            } else {
                st.push({pos, h});
            }
        }

        while (!st.empty()) {
            mp[st.top().first] = st.top().second;
            st.pop();
        }

        vector<int> result;
        for (int pos : positions) {
            if (mp.count(pos)) {
                result.push_back(mp[pos]);
            }
        }

        return result;
    }
};