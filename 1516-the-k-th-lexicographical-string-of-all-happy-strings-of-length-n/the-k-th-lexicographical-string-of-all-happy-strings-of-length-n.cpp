class Solution {
public:
    void getstore(vector<string>& store, int n, int idx, string curr) {
        if (idx == n) {
            store.push_back(curr);
            return;
        }
        int l = curr.size();
        if (l == 0 || curr[l - 1] != 'a') {
            curr.push_back('a');
            getstore(store, n, idx + 1, curr);
            curr.pop_back();
        }
        if (l == 0 || curr[l - 1] != 'b') {
            curr.push_back('b');
            getstore(store, n, idx + 1, curr);
            curr.pop_back();
        }
        if (l == 0 || curr[l - 1] != 'c') {
            curr.push_back('c');
            getstore(store, n, idx + 1, curr);
            curr.pop_back();
        }
    }
    string getHappyString(int n, int k) {
        vector<string> store;
        string curr = "";
        getstore(store, n, 0, curr);
        sort(store.begin(), store.end());
        if (store.size() >= k) {
            return store[k - 1];
        }
        return "";
    }
};