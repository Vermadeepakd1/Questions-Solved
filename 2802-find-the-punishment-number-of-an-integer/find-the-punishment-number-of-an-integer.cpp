class Solution {
public:
    bool canPartition(string s, int target, int index = 0, int currentSum = 0) {
    if (index == s.length()) {
        return currentSum == target;
    }
    
    int num = 0;
    for (int i = index; i < s.length(); i++) {
        num = num * 10 + (s[i] - '0');
        if (currentSum + num <= target && canPartition(s, target, i + 1, currentSum + num)) {
            return true;
        }
    }
    
    return false;
    }

    int punishmentNumber(int n) {
        int total = 0;
        for (int i = 1; i <= n; i++) {
            string squareStr = to_string(i * i);
            if (canPartition(squareStr, i)) {
                total += i * i;
            }
        }
        return total;
    }
};