#include <chrono>

#include "Time.hpp"

namespace
{
    using Clock = std::chrono::high_resolution_clock;
    auto StartTime = Clock::now();
    auto LastFrame = Clock::now();
}

float Time::Delta = 0.0f;
float Time::Total = 0.0f;

void Time::update()
{
    auto now = Clock::now();

    std::chrono::duration<float> delta = now - LastFrame;
    Delta = delta.count();

    std::chrono::duration<float> total = now - StartTime;
    Total = total.count();

    LastFrame = now;
}

