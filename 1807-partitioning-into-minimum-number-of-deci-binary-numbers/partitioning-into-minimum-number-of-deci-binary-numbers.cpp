class Solution {
public:
    int minPartitions(string n) {
        char maxchar = *max_element(n.begin(),n.end());
        return maxchar - '0';
    }
};