include(CTest)

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.0.1 
)

FetchContent_MakeAvailable(Catch2)

set(UNIONS_TEST_NAME test_unions)

set(UNIONS_TEST_HEADERS
)

set(UNIONS_TEST_SOURCES
	test_main.cpp
  test_visitor.cpp
)

add_executable(${UNIONS_TEST_NAME}
    ${UNIONS_TEST_HEADERS}
    ${UNIONS_TEST_SOURCES}
)

target_include_directories(${UNIONS_TEST_NAME}
  PRIVATE ${CMAKE_SOURCE_DIR}/unions/
)

target_link_libraries(${UNIONS_TEST_NAME}
    PRIVATE Catch2::Catch2WithMain
)    

add_test(NAME ${UNIONS_TEST_NAME}
         COMMAND  ${UNIONS_TEST_NAME})