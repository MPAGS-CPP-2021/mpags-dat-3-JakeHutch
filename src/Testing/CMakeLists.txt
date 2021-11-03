
# create catch interface library
add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE ${CMAKE_CURRENT_LIST_DIR})
target_compile_features(Catch INTERFACE cxx_noexcept)

# Test TransformChar functions
add_executable(testTransformChar testTransformChar.cpp)
target_link_libraries(testTransformChar MPAGSCipher Catch)
add_test(NAME test-transformchar COMMAND testTransformChar)

# Test ProcessCommandLine functions
add_executable(testProcessCommandLine testProcessCommandLine.cpp)
target_link_libraries(testProcessCommandLine MPAGSCipher Catch)
add_test(NAME test-processcommandline COMMAND testProcessCommandLine)

# Test CaesarCipher functions
add_executable(testCaesarCipher testCaesarCipher.cpp)
target_link_libraries(testCaesarCipher MPAGSCipher Catch)
add_test(NAME test-caesarcipher COMMAND testCaesarCipher)