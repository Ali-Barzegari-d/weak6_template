cmake_minimum_required(VERSION 3.16)
project(csi2372_lab LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ---- Enable CTest ----
include(CTest)

# --- Task 1: Parse ---
add_library(parse src/parse.cpp)
target_include_directories(parse PUBLIC include)

add_executable(parse_tests tests/test_parse.cpp)
target_link_libraries(parse_tests PRIVATE parse)
add_test(NAME parse_tests COMMAND parse_tests)

# --- Task 2: Ranges Pipeline ---
add_library(ranges_pipeline src/ranges_pipeline.cpp)
target_include_directories(ranges_pipeline PUBLIC include)

add_executable(ranges_pipeline_tests tests/test_ranges_pipeline.cpp)
target_link_libraries(ranges_pipeline_tests PRIVATE ranges_pipeline)
add_test(NAME ranges_pipeline_tests COMMAND ranges_pipeline_tests)

# --- Task 3: PersonDirectory ---
add_library(person_directory src/person_directory.cpp)
target_include_directories(person_directory PUBLIC include)

add_executable(person_directory_tests tests/test_person_directory.cpp)
target_link_libraries(person_directory_tests PRIVATE person_directory)
add_test(NAME person_directory_tests COMMAND person_directory_tests)

# --- Task 4: IterableProcessor ---
add_library(iterable_processor src/iterable_processor.cpp)
target_include_directories(iterable_processor PUBLIC include)

add_executable(iterable_processor_tests tests/test_iterable_processor.cpp)
target_link_libraries(iterable_processor_tests PRIVATE iterable_processor)
add_test(NAME iterable_processor_tests COMMAND iterable_processor_tests)
