# Include the directory itself as a path to include directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Create a variable containing all .cpp files:
FILE(GLOB files *.cpp)

# Create an executable file from sources:
add_library(SampleGenerator SHARED ${files})
target_link_libraries(SampleGenerator ${DisCODe_LIBRARIES} ${Boost_LIBRARIES})

INSTALL_COMPONENT(SampleGenerator)
