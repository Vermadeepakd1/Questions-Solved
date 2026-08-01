class Solution {
    bool checkwin(vector<int>& nums, int aturn, int csum1, int csum2, int start,
                  int end) {
        if (start > end) {
            if (csum1 >= csum2)
                return true;
            return false;
        }

        if (aturn) {
            return checkwin(nums, !aturn, csum1 + nums[start], csum2, start + 1, end) ||
                   checkwin(nums, !aturn, csum1 + nums[end], csum2, start, end - 1);
        } else {
            return checkwin(nums, !aturn, csum1, csum2 + nums[start], start + 1, end) &&
                   checkwin(nums, !aturn, csum1, csum2 + nums[end], start, end - 1);
        }
    }

public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        return checkwin(nums, true, 0, 0, 0,
                        n - 1); // nums, Aturn , currsum1, currsum2, start, end
    }
};