#include "gtest/gtest.h"
#include "src/csvtojson.h"
#include "rapidjson/include/rapidjson/document.h"
#include "src/csvtojson.h"
#include <sstream>

TEST(printcsv, withoutextension){
  csvtojson c;
  stringstream out;
  c.printcsv("test1",3, out);
  string result = out.str();
  string ans= "JohnBluetrueBobRedfalseJhonnyGreentrue";
  EXPECT_EQ(result,ans);
}
TEST(printcsv, withextension){
  csvtojson c;
  stringstream out;
  c.printcsv("test1.csv",3, out);
  string result = out.str();
  string ans= "JohnBluetrueBobRedfalseJhonnyGreentrue";
  EXPECT_EQ(result,ans);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
