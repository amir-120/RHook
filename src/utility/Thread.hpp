#pragma once

#include <memory>
#include <vector>

namespace RHook {
struct ThreadState {
    uint32_t threadID{0};
    bool suspended{false};

    using Ptr = std::unique_ptr<ThreadState>;
};

using ThreadStates = std::vector<ThreadState::Ptr>;

ThreadStates SuspendThreads();
void ResumeThreads(const ThreadStates& states);

struct ThreadSuspender {
    ThreadSuspender();

    virtual ~ThreadSuspender();

    void suspend() {
        states = SuspendThreads();
    }

    void Resume();

    ThreadStates states{};
};
}