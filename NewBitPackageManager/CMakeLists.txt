set(EXECUTABLE_NAME NewBitPackageManager)

FILE(GLOB HEADER_FILES src/*.h)
FILE(GLOB SOURCE_FILES src/*.cpp)
add_library(${EXECUTABLE_NAME} SHARED ${HEADER_FILES} ${SOURCE_FILES})

nb_target_add_libraries(${EXECUTABLE_NAME})