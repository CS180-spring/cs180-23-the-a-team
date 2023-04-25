#include "gtest/gtest.h"
#include "src/csvtojson.h"
#include "rapidjson/include/rapidjson/document.h"
#include "src/csvtojson.h"

TEST(printcsv, withoutextension){
  csvtojson c;
  c.printcsv("test1",3);
}
TEST(printcsv, withextension){
  csvtojson c;
  c.printcsv("test1.csv",3);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
