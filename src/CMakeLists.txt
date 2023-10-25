project(RHook)

set(HOOKS_SRC
    hooks/D3D9Hook.cpp
    hooks/DXGIHook.cpp
    hooks/D3D10Hook.cpp
    hooks/D3D11Hook.cpp
    hooks/D3D12Hook.cpp
    hooks/OpenGLHook.cpp
    hooks/PresentHook.cpp
    hooks/VulkanHook.cpp
    hooks/WindowsMessageHook.cpp
)

set(UTILITIES_SRC
    utility/Address.cpp
    utility/Detour.cpp
    utility/SmartFunctionHook.cpp
    utility/PointerHook.cpp
    utility/ProtectionOverride.cpp
    utility/String.cpp
    utility/Thread.cpp
    utility/VtableHook.cpp
    utility/Module.cpp
)

set(LOGGING_SRC
    log/Logging.hpp
    log/Logging.cpp
)

set(INCLUDE_SRC_HOOKS
    ${INCLUDE_HEADERS_DIR}/RHook/hooks/D3D9VMTIndices.hpp
    ${INCLUDE_HEADERS_DIR}/RHook/hooks/D3DDXGIVMTIndices.hpp
    ${INCLUDE_HEADERS_DIR}/RHook/hooks/D3D9Hook.hpp
    ${INCLUDE_HEADERS_DIR}/RHook/hooks/DXGIHook.hpp
    ${INCLUDE_HEADERS_DIR}/RHook/hooks/D3D10Hook.hpp
    ${INCLUDE_HEADERS_DIR}/RHook/hooks/D3D11Hook.hpp
    ${INCLUDE_HEADERS_DIR}/RHook/hooks/D3D12Hook.hpp
    ${INCLUDE_HEADERS_DIR}/RHook/hooks/OpenGLHook.hpp
    ${INCLUDE_HEADERS_DIR}/RHook/hooks/PresentHook.hpp
    ${INCLUDE_HEADERS_DIR}/RHook/hooks/VulkanHook.hpp
    ${INCLUDE_HEADERS_DIR}/RHook/hooks/WindowsMessageHook.hpp
)

set(INCLUDE_SRC_UTILS
    ${INCLUDE_HEADERS_DIR}/RHook/utility/Address.hpp
    ${INCLUDE_HEADERS_DIR}/RHook/utility/Detour.hpp
    ${INCLUDE_HEADERS_DIR}/RHook/utility/SmartFunctionHook.hpp
    ${INCLUDE_HEADERS_DIR}/RHook/utility/PointerHook.hpp
    ${INCLUDE_HEADERS_DIR}/RHook/utility/ProtectionOverride.hpp
    ${INCLUDE_HEADERS_DIR}/RHook/utility/String.hpp
    ${INCLUDE_HEADERS_DIR}/RHook/utility/Thread.hpp
    ${INCLUDE_HEADERS_DIR}/RHook/utility/VtableHook.hpp
    ${INCLUDE_HEADERS_DIR}/RHook/utility/Module.hpp
)

source_group("Include" FILES ${INCLUDE_HEADERS_DIR}/RHook/RenderHook.hpp)
source_group("Include/log" FILES ${INCLUDE_HEADERS_DIR}/RHook/log/Logging.hpp)
source_group("Include/hooks" FILES ${INCLUDE_SRC_HOOKS})
source_group("Include/utility" FILES ${INCLUDE_SRC_UTILS})

source_group("Hooks" FILES ${HOOKS_SRC})
source_group("Utilties" FILES ${UTILITIES_SRC})
source_group("Logging" FILES ${LOGGING_SRC})

source_group("Init" FILES Initialization.cpp)

add_library(${PROJECT_NAME} STATIC
            Initialization.cpp
            ${INCLUDE_HEADERS_DIR}/RHook/RenderHook.hpp
            ${INCLUDE_HEADERS_DIR}/RHook/log/Logging.hpp
            ${LOGGING_SRC}
            ${INCLUDE_SRC_HOOKS}
            ${INCLUDE_SRC_UTILS}
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

target_link_libraries(${PROJECT_NAME} PUBLIC Detours libffi fmt d3d9 d3d10 d3d11 d3d12 OpenGL32 ${Vulkan_LIBRARY})
target_compile_options(${PROJECT_NAME} PUBLIC /GS- /GR-)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)

include_directories(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${PROJECT_NAME} ${Vulkan_INCLUDE_DIRS})
include_directories(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/include)

set_target_properties(${PROJECT_NAME} PROPERTIES 
OUTPUT_NAME RHook)

target_compile_options(${PROJECT_NAME} PUBLIC /EHa)