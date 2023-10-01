#include <RHook/utility/OriginalOverride.hpp>
#include <RHook/utility/Module.hpp>
#include <RHook/utility/ProtectionOverride.hpp>

#include <vector>

namespace RHook {

	OriginalOverride::OriginalOverride(void* address)
	{
		RestoreOriginal();
	}

	OriginalOverride::~OriginalOverride()
	{
		RestoreModified();
	}

	void OriginalOverride::RestoreOriginal() 
	{
		auto originalBytes = GetOriginalBytes(m_Ptr);

		if (originalBytes) {

			m_ModifiedBytes.resize(originalBytes->size());
			memcpy(m_ModifiedBytes.data(), m_Ptr, originalBytes->size());

			ProtectionOverride protectionOverride{ m_Ptr, originalBytes->size(), PAGE_EXECUTE_READWRITE };

			memcpy(m_Ptr, originalBytes->data(), originalBytes->size());
		}
	}

	void OriginalOverride::RestoreModified()
	{
		if (m_ModifiedBytes.size()) {
			ProtectionOverride protectionOverride{ m_Ptr, m_ModifiedBytes.size(), PAGE_EXECUTE_READWRITE };

			memcpy(m_Ptr, m_ModifiedBytes.data(), m_ModifiedBytes.size());

			m_ModifiedBytes.clear();
		}
	}

}
