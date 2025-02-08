class NumberContainers
{
    public:
        unordered_map<int, int> mp;
    unordered_map<int, set < int>> sec;
    NumberContainers() {}

    void change(int index, int number)
    {
        if (mp.find(index) != mp.end())
        {
            int oldnumber = mp[index];
            sec[oldnumber].erase(index);
            if (sec[oldnumber].empty())
            {
                sec.erase(oldnumber);
            }
        }
        mp[index] = number;
        sec[number].insert(index);
    }

    int find(int number)
    {
        if (sec.find(number) != sec.end() && !sec[number].empty())
        {
            return *sec[number].begin();
        }
        return -1;
    }
};

/**
 *Your NumberContainers object will be instantiated and called as such:
 *NumberContainers* obj = new NumberContainers();
 *obj->change(index,number);
 *int param_2 = obj->find(number);
 */