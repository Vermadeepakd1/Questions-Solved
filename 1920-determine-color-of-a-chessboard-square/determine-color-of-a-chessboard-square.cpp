class Solution {
public:
    bool squareIsWhite(string coordinates) {
        int first = coordinates[0] - 'a' + 1;
        int second = coordinates[1] - '0';
        if ((first & 1) == (second & 1)) {
            return false;
        }
        return true;
    }
};