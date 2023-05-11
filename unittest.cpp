#include "gtest/gtest.h"
#include "src/csvtojson.h"
#include "rapidjson/include/rapidjson/document.h"
#include "src/csvtojson.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "src/json.h"

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

/*sTEST(JsonTest, ParseErrorTest) {
   // Create a file with a JSON syntax error
  std::ofstream file("data.json");
  file << "{ \"name\": \"John\", \"age\": 30, }"; // Syntax error: trailing comma
  file.close();

  // Call the function being tested
  Json json;
  json.parseError();

  // Check that the function output contains the expected error message
  testing::internal::CaptureStdout();
  json.parseError();
  std::string output = testing::internal::GetCapturedStdout();
  bool hasError = output.find("Error(offset ") != std::string::npos;
  bool hasMissingNameError = output.find("Missing a name") != std::string::npos;
  EXPECT_TRUE(hasError && hasMissingNameError);

  // Remove the test file
  std::remove("data.json");
}*/

TEST(JsonTest, WriteJsonTest) {
  Json json;
  json.writeJson();

  // Read the contents of the output file
  std::ifstream inputFile("output.json");
  std::stringstream buffer;
  buffer << inputFile.rdbuf();
  std::string fileContents = buffer.str();

  // Remove tabs from the file contents
  fileContents.erase(std::remove(fileContents.begin(), fileContents.end(), '\t'), fileContents.end());

  // Check that the output file has the right JSON data
  std::string expectedOutput = "{\n\"people\": [{\n\"id\": \"9873e87e879ueid\",\n\"name\": \"Farnaz\",\n\"age\": 23,\n\"college\": \"UC Riverside\"\n}, {\n\"id\": \"98e89r8983009id\",\n\"name\": \"Golnaz\",\n\"age\": 27,\n\"college\": \"UC Berkely\"\n}, {\n\"id\": \"9898378747382id\",\n\"name\": \"Niloofar\",\n\"age\": 30,\n\"college\": \"UCLA\"\n}, {\n\"id\": \"959067fs9d798id\",\n\"name\": \"Muneeb\",\n\"age\": 23,\n\"college\": \"UC Riverside\"\n}]\n}";

  EXPECT_EQ(fileContents, expectedOutput);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
