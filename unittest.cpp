#include "gtest/gtest.h"
#include "src/csvtojson.h"
#include "rapidjson/include/rapidjson/document.h"
#include "src/csvtojson.h"
#include <iostream>
#include <fstream>
#include <sstream>

//TEST(s) goes above main
TEST(csvtojson, withoutextension){
  csvtojson c;
  stringstream ss;
  c.printcsv("test1", 3, ss);
  EXPECT_EQ(ss, "JohnBluetrueBobRedfalseJhonnyGreentrue");
}

TEST(csvtojson, withextension){
  csvtojson c;
  stringstream ss;
  c.printcsv("test1.csv", 3,ss);
  EXPECT_EQ(ss, "JohnBluetrueBobRedfalseJhonnyGreentrue");
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
