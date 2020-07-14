class Solution {
public:
    double angleClock(int hour, int minutes) {
        double min = minutes * 6;
        double hr = (hour%12 + (double)minutes/60) * 30;
        return (abs(hr - min) < 360 - abs(hr - min)) ? abs(hr - min) : 360 - abs(hr - min);
    }
};
