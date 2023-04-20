#include "gtest/gtest.h"
#include "src/csvtojson.h"
#include "supportforUnitTesting/test1.csv"

//TEST(s) goes above main
TEST (CSVTOJSONTESTING, allstring){
  csvtojson ctoj1;
  ctoj1.addjson("test1.csv");
  //EXPECT_STREQ();
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
