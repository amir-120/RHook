#include <mutex>

#include <Windows.h>
#include <TlHelp32.h>

#include "Log/Logging.hpp"
#include "Thread.hpp"

namespace RHook {
	namespace detail {
		std::mutex g_SuspendMutex{};
	}

	ThreadStates SuspendThreads() {
		ThreadStates states{};

		const auto pid = GetCurrentProcessId();
		const auto snapshotHandle = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, pid);

		if (snapshotHandle == nullptr || snapshotHandle == INVALID_HANDLE_VALUE) {
			return states;
		}

		THREADENTRY32 te{};
		te.dwSize = sizeof(THREADENTRY32);

		if (!Thread32First(snapshotHandle, &te)) {
			CloseHandle(snapshotHandle);
			return states;
		}

		const auto currentThreadID = GetCurrentThreadId();

		do {
			if (te.th32OwnerProcessID == pid && te.th32ThreadID != currentThreadID) {
				auto threadHandle = OpenThread(THREAD_SUSPEND_RESUME, FALSE, te.th32ThreadID);

				if (threadHandle != nullptr && snapshotHandle != INVALID_HANDLE_VALUE) {
					auto state = std::make_unique<ThreadState>();

					RH_RHOOK_INFO("[THREAD] Suspending {}", (uint32_t)te.th32ThreadID);

					state->threadID = te.th32ThreadID;
					state->suspended = SuspendThread(threadHandle) > 0;
					states.emplace_back(std::move(state));

					CloseHandle(threadHandle);
				}
			}
		} while (Thread32Next(snapshotHandle, &te));

		CloseHandle(snapshotHandle);
		return states;
	}

	void ResumeThreads(const ThreadStates& states) {
		for (const ThreadState::Ptr& state : states) {
			auto threadHandle = OpenThread(THREAD_SUSPEND_RESUME, FALSE, state->threadID);

			if (threadHandle != nullptr) {
				RH_RHOOK_INFO("[THREAD] Resuming {}", state->threadID);

				ResumeThread(threadHandle);
				CloseHandle(threadHandle);
			}
		}
	}

	ThreadSuspender::ThreadSuspender() {
		detail::g_SuspendMutex.lock();
		states = SuspendThreads();
	}

	ThreadSuspender::~ThreadSuspender() {
		ResumeThreads(states);
		detail::g_SuspendMutex.unlock();
	}

	void ThreadSuspender::Resume() {
		ResumeThreads(states);
		states.clear();
	}
}
