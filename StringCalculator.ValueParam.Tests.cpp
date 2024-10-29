#include "StringCalculator.h"
#include <gtest/gtest.h>
#include <tuple>
using namespace std;

//fixture class
class StringCalculatorAddFixture:public testing::Test
{
  protected:
    StringCalculator *objUnderTest;
    void SetUp() override
    {
       objUnderTest=new StringCalculator();
    }
    void TearDown()
    {
       delete objUnderTest;
    }
};

//value parameterized fixture
class StringCalculatorAddParameterizedFixture:public StringCalculatorAddFixture, public testing::WithParamInterface<tuple<string,int>>
{
};

INSTANTIATE_TEST_SUITE_P(ValidValDataSet, StringCalculatorAddParameterizedFixture, testing::Values(
  make_tuple("", 0), make_tuple("0", 0), make_tuple("1", 1), make_tuple("1,2", 3), make_tuple("1,2,3", 6), make_tuple("1*****2", 3),
  make_tuple("1,2000,2", 3), make_tuple("1[#]$$$[****]//2", 3)
));

INSTANTIATE_TEST_SUITE_P(NegetiveValDataSet, StringCalculatorAddParameterizedFixture, testing::Values(
  make_tuple("", 15), make_tuple("0", 14), make_tuple("1", 12), make_tuple("1,2", 8)
));


TEST_P(StringCalculatorAddParameterizedFixture, DataDrivenTestCase)
{
    string input = std::get<0>(GetParam());
    int expectedValue = std::get<1>(GetParam());
    int actualValue = objUnderTest->Add(input);
    ASSERT_EQ(actualValue, expectedValue);
}

TEST_F(StringCalculatorAddFixture, ThrowInvalidArgumentExceptionForNegetiveNum)
{
    string input = "1,-2";
    EXPECT_THROW(objUnderTest->Add(input), invalid_argument);
}
