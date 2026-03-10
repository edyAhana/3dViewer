#ifndef TIME_HPP
#define TIME_HPP

class Time {
private:
    static float Delta;
    static float Total;
public:
    static void update();
    static float get_delta() { return Delta; }
    static float get_total() { return Total; }
};


#endif
