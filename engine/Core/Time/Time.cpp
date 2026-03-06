#include <chrono>

#include "Time.hpp"

namespace
{
    using Clock = std::chrono::high_resolution_clock;
    auto StartTime = Clock::now();
    auto LastFrame = Clock::now();
}

double Time::Delta = 0.0f;
double Time::Total = 0.0f;

void Time::update()
{
    auto now = Clock::now();

    std::chrono::duration<double> delta = now - LastFrame;
    Delta = delta.count();

    std::chrono::duration<double> total = now - StartTime;
    Total = total.count();

    LastFrame = now;
}

