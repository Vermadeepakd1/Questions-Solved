class MapSum {
public:
    unordered_map<string, int> mp;
    MapSum() {}

    void insert(string key, int val) { mp[key] = val; }

    int sum(string prefix) {
        int count = 0;
        for (auto it : mp) {
            if (it.first.starts_with(prefix)) {
                count += it.second;
            }
        }
        return count;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */