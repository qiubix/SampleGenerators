INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR})

create_test_suite(ImageLoaderTest ImageLoaderTest.cpp ImageLoader)
file(COPY first.testfile DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY first.testfile DESTINATION ${CMAKE_BINARY_DIR}/Debug)
file(COPY second.testfile DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY second.testfile DESTINATION ${CMAKE_BINARY_DIR}/Debug)
file(COPY ../data/43074.jpg DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ../data/43074.jpg DESTINATION ${CMAKE_BINARY_DIR}/Debug)

create_test_suite(CvMatGeneratorTest CvMatGeneratorTest.cpp CvMatGenerator)

create_test_suite(CvMatSinkTest CvMatSinkTest.cpp CvMatSink)
