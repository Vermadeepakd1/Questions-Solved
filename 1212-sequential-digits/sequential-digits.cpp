class Solution {
public:
    void findseq(vector<int>& result, int num, int low, int high) {
        if (num <= high && num >= low) {
            result.push_back(num);
        }
        for (int i = num + 1; i <= 9; i++) {
            num = num * 10 + i;
            if (num <= high && num >= low) {
                result.push_back(num);
            }
        }
    }
    vector<int> sequentialDigits(int low, int high) {
        vector<int> result;
        for (int i = 1; i < 9; i++) {
            findseq(result, i, low, high);
        }
        sort(result.begin(), result.end());
        return result;
    }
};