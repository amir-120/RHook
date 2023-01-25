project(libffi C)
set(LIBFFI_PATH libffi)
set(LIBFFI_PROJEC_NAME libffi)

set(LIBFFI_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR}/libffi)

set(SOURCES_LIST
    ${LIBFFI_PATH}/src/closures.c
    ${LIBFFI_PATH}/src/tramp.c
    ${LIBFFI_PATH}/src/java_raw_api.c
    ${LIBFFI_PATH}/src/prep_cif.c
    ${LIBFFI_PATH}/src/raw_api.c
    ${LIBFFI_PATH}/src/types.c)

if(CMAKE_BUILD_TYPE MATCHES DEBUG)
    list(APPEND SOURCES_LIST ${LIBFFI_PATH}/src/debug.c)
    add_definitions(-DFFI_DEBUG)
endif()

include(configure_platform.cmake)
include(configure_options.cmake)

file(COPY ${LIBFFI_PATH}/src/${TARGETDIR}/ffitarget.h DESTINATION ${LIBFFI_BINARY_DIR}/include)

include_directories(${LIBFFI_BINARY_DIR}/include)
include_directories(${LIBFFI_BINARY_DIR})

add_definitions(-DFFI_BUILDING)

add_library(${LIBFFI_PROJEC_NAME} STATIC 
            ${SOURCES_LIST})

if(MSVC)
    add_definitions(-DFFI_BUILDING)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
elseif(CMAKE_SYSTEM_NAME MATCHES Darwin)
    set(CMAKE_MACOSX_RPATH 1)
endif()

set_target_properties(${LIBFFI_PROJEC_NAME} PROPERTIES OUTPUT_NAME libffi)

#install(TARGETS ${LIBFFI_PROJEC_NAME} #ffi_shared
#    EXPORT ${PROJECT_NAME}Targets
#    RUNTIME DESTINATION bin
#    ARCHIVE DESTINATION lib
#    LIBRARY DESTINATION lib)

#install(EXPORT ${PROJECT_NAME}Targets
#    DESTINATION share/${PROJECT_NAME})

#install(FILES
#    ${LIBFFI_BINARY_DIR}/include/ffi.h
#    ${LIBFFI_BINARY_DIR}/include/ffitarget.h
#    DESTINATION include)
