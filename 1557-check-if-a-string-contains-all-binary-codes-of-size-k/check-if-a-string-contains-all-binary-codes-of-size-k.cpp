class Solution {
    string binaryrep(int n, int len) {
        return bitset<64>(n).to_string().substr(64 - len - 1);
    }

public:
    bool hasAllCodes(string s, int k) {
        set<string> st;
        int n = s.length();
        for (int i = 0; i <= n - k; i++) {
            string temp = s.substr(i, k);
            st.insert(temp);
        }
        if (st.size() == (1 << k))
            return true;
        return false;
    }
};