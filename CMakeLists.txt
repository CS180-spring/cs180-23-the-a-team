CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

SET(CMAKE_CXX_STANDARD 11)

ADD_SUBDIRECTORY(googletest)
#ADD_SUBDIRECTORY(rapidjson)

ADD_EXECUTABLE(FriendlyCDB
    main.cpp src/gui.cpp src/collection.cpp src/json.cpp src/csvtojson.cpp
)

ADD_EXECUTABLE(test
    unittest.cpp src/gui.cpp src/collection.cpp src/json.cpp src/csvtojson.cpp
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
