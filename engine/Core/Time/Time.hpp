#ifndef TIME_HPP
#define TIME_HPP

class Time {
private:
    static double Delta;
    static double Total;
public:
    static void update();
    static double get_delta();
    static double get_total();
};


#endif
