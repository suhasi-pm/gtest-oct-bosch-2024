#include "TestChallenge.h"
#include <gtest/gtest.h>
#include <tuple>
using namespace std;

class TestChallengeFixture:public testing::Test{
  protected:
    TestChallenge *objUnderTest;
  void SetUp() override {
      objUnderTest=new TestChallenge();
  }
  void TearDown(){
        delete objUnderTest;
  }
};

class TestChallengeParameterizedFixture:
public TestChallengeFixture,
public testing::WithParamInterface<tuple<string,int>>{

};
INSTANTIATE_TEST_SUITE_P(ValuesDataSet,TestChallengeParameterizedFixture,testing::Values(
  make_tuple(1,0,1),
  make_tuple(2,4,6),
  make_tuple(100,250,350)
));


TEST_P(StringCalculatorAddParameterizedFixture, DataDrivenTestCase){
    int input1 = std::get<0>(GetParam());
    int input2 = std::get<1>(GetParam());
    int expectedValue = std::get<2>(GetParam());
    int actualValue = objUnderTest->add(input);
    ASSERT_EQ(actualValue,expectedValue);
}
