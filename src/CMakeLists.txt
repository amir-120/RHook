set(INCLUDE_SRC
    Include/RenderHook.hpp
)

set(LOGGING_SRC
    Log/Logging.hpp
    Log/Logging.cpp
)

set(HOOKS_SRC
    hooks/D3D9VMTIndices.hpp
    hooks/D3DDXGIVMTIndices.hpp
    hooks/D3D9Hook.cpp
    hooks/D3D9Hook.hpp
    hooks/DXGIHook.cpp
    hooks/DXGIHook.hpp
    hooks/D3D10Hook.cpp
    hooks/D3D10Hook.hpp
    hooks/D3D11Hook.cpp
    hooks/D3D11Hook.hpp
    hooks/D3D12Hook.cpp
    hooks/D3D12Hook.hpp
    hooks/OpenGLHook.cpp
    hooks/OpenGLHook.hpp
    hooks/PresentHook.cpp
    hooks/PresentHook.hpp
    hooks/VulkanHook.cpp
    hooks/VulkanHook.hpp
    hooks/WindowsMessageHook.cpp
    hooks/WindowsMessageHook.hpp
)

set(UTILITIES_SRC
    utility/Address.cpp
    utility/Address.hpp
    utility/FunctionHook.cpp
    utility/FunctionHook.hpp
    utility/SmartFunctionHook.cpp
    utility/SmartFunctionHook.hpp
    utility/PointerHook.cpp
    utility/PointerHook.hpp
    utility/VtableHook.cpp
    utility/VtableHook.hpp
    utility/Module.hpp
    utility/Module.cpp
)

source_group("Include" FILES ${INCLUDE_SRC})
source_group("Logging" FILES ${LOGGING_SRC})
source_group("Hooks" FILES ${HOOKS_SRC})
source_group("Utilties" FILES ${UTILITIES_SRC})
source_group("Application" FILES ${APPLICATION_SRC})

add_library(${CMAKE_PROJECT_NAME} STATIC
            Initialization.cpp
            ${INCLUDE_SRC}
            ${LOGGING_SRC}
            ${HOOKS_SRC}
            ${UTILITIES_SRC}
)

find_package(Vulkan REQUIRED)
if (NOT ${Vulkan_INCLUDE_DIRS} STREQUAL "")
	set(VULKAN_PATH ${Vulkan_INCLUDE_DIRS})
	STRING(REGEX REPLACE "/Include" "" VULKAN_PATH ${VULKAN_PATH})
endif()

if(NOT Vulkan_FOUND)
	message(STATUS "Failed to locate Vulkan SDK, retrying...")
	if(EXISTS "${VULKAN_PATH}")
		message(STATUS "Vulkan SDK located: ${VULKAN_PATH}")
	else()
		message("Error: Unable to locate Vulkan SDK.'")
		return()
	endif()
endif()

link_directories(${VULKAN_PATH}/Bin;${VULKAN_PATH}/Lib;)

target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC Detours libffi spdlog d3d9 d3d10 d3d11 d3d12 OpenGL32 ${Vulkan_LIBRARY})
target_compile_options(${CMAKE_PROJECT_NAME} PUBLIC /GS- /GR-)
target_compile_features(${CMAKE_PROJECT_NAME} PUBLIC cxx_std_20)

include_directories(${CMAKE_PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_PROJECT_NAME} ${Vulkan_INCLUDE_DIRS})
include_directories(${CMAKE_PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/Include)