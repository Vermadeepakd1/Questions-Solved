class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int ax1 = rec1[0], ay1 = rec1[1], ax2 = rec1[2], ay2 = rec1[3];
        int bx1 = rec2[0], by1 = rec2[1], bx2 = rec2[2], by2 = rec2[3];

        bool x_overlap = min(ax2, bx2) > max(ax1, bx1);
        bool y_overlap = min(ay2, by2) > max(ay1, by1);

        return x_overlap && y_overlap;
    }
};