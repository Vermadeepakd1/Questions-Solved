class Solution {
public:
    double angleClock(int hour, int minutes) {
        // minute hand = 1hr = 360 , 1minute = 6
        // hour hand = 12 hr = 360, 1hr = 30, 1 min =  1/2
        double minangle = minutes * 6;
        double hrangle = hour * 30 + minutes * 0.5;
        double diff = abs(hrangle - minangle);
        return min(diff, 360 - diff);
    }
};