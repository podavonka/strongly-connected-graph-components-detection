#ifndef B6B36PCC_SEMESTRAL_WORK_TIMER_HPP
#define B6B36PCC_SEMESTRAL_WORK_TIMER_HPP

#include <chrono>

namespace timer {
    auto now() {
        return std::chrono::high_resolution_clock::now();
    }

    template <typename TimePoint>
    long long to_ms(TimePoint tp) {
        return std::chrono::duration_cast<std::chrono::milliseconds>(tp).count();
    }
}

#endif //B6B36PCC_SEMESTRAL_WORK_TIMER_HPP
