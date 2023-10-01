#pragma once

#include "ProtectionOverride.hpp"
#include <vector>

namespace RHook {
	class OriginalOverride {
	public:
		OriginalOverride(void* address);
		~OriginalOverride();

		void RestoreOriginal();

		void RestoreModified();
	
	private:
		std::vector<uint8_t> m_ModifiedBytes{};
		void* m_Ptr{};
	};
}