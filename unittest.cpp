#include "gtest/gtest.h"
#include "src/csvtojson.h"
#include "rapidjson/include/rapidjson/document.h"
#include "src/csvtojson.h"
#include <iostream>
#include <fstream>
#include <sstream>

/*
//TEST(s) goes above main
TEST(csvtojson, withoutextension){
  csvtojson c;
  stringstream ss;
  c.printcsv("test1", 3, ss);
 // EXPECT_EQ(ss, "JohnBluetrueBobRedfalseJhonnyGreentrue");
}

TEST(csvtojson, withextension){
  csvtojson c;
  stringstream ss;
  c.printcsv("test1.csv", 3,ss);
  //EXPECT_EQ(ss, "JohnBluetrueBobRedfalseJhonnyGreentrue");
}
*/

TEST(JsonTest, ParseErrorTest) {
  // Create a file with a JSON syntax error
  std::ofstream file("data.json");
  file << "{ 'name': 'John', 'age': 30, }"; // Syntax error: trailing comma
  file.close();

  // Call the function being tested
  Json json;
  json.parseError();

  // Check that the function output contains the expected error message
  testing::internal::CaptureStdout();
  json.parseError();
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_TRUE(output.find("Error(offset 24):") != std::string::npos);
  EXPECT_TRUE(output.find("trailing comma") != std::string::npos);

  // Remove the test file
  std::remove("data.json");
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
