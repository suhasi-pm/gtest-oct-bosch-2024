#include "StringCalculator.h"
#include <gtest/gtest.h>

//Fixture Class

class StringCalculatorAddFixture:public testing::Test{
  protected:
    StringCalculator *objUnderTest;
  void SetUp() override {
      objUnderTest=new StringCalculator();
  }
  void TearDown(){
        delete objUnderTest;
  }
};

TEST_F(StringCalculatorAddFixture, Returns_0_For_Empty){
    string input="";
    int expectedValue=0;
    int actualValue=objUnderTest->Add(input);
    ASSERT_EQ(actualValue,expectedValue);
}

TEST_F(StringCalculatorAddFixture, Returns_0_For_0){
    string input="0";
    int expectedValue=0;
    int actualValue=objUnderTest->Add(input);
    ASSERT_EQ(actualValue,expectedValue);
}

TEST(StringCalculatorAddFixture, Returns_1_For_1)
{
    string input="1";
    int expectedValue=1;
    int actualValue=objUnderTest->Add(input);
    ASSERT_EQ(actualValue,expectedValue);
}

TEST(StringCalculatorAddFixture, Two_Comma_Delimited)
{
    string input="1,2";
    int expectedValue=3;
    int actualValue=objUnderTest->Add(input);
    ASSERT_EQ(actualValue,expectedValue);
}

TEST(StringCalculatorAddFixture, Multiple_Comma_Delimited)
{
    string input="1,2,3";
    int expectedValue=6;
    int actualValue=objUnderTest->Add(input);
    ASSERT_EQ(actualValue,expectedValue);
}

TEST(StringCalculatorAddFixture, Delimited_With_Newline_And_Comma)
{
    string input="1\n2,3";
    int expectedValue=6;
    int actualValue=objUnderTest->Add(input);
    ASSERT_EQ(actualValue,expectedValue);
}

TEST(StringCalculatorAddFixture, Delimiter)
{
    string input="/\n1;2";
    int expectedValue=3;
    int actualValue=objUnderTest->Add(input);
    ASSERT_EQ(actualValue,expectedValue);
}

TEST(StringCalculatorAddFixture, Negative_Number)
{
    string input="1,-2,-3";
    int expectedValue=6;
    // int actualValue=objUnderTest->Add(input);
    ASSERT_THROW(objUnderTest.Add(input),std::invalid_argument);
}

TEST(StringCalculatorAddFixture, Number_Over_1000)
{
    string input="1,2000,3";
    int expectedValue=4;
    int actualValue=objUnderTest->Add(input);
    ASSERT_EQ(actualValue,expectedValue);
}

TEST(StringCalculatorAddFixture, Multicharacter_Delimiter)
{
    string input="1*****\n2****3";
    int expectedValue=6;
    int actualValue=objUnderTest->Add(input);
    ASSERT_EQ(actualValue,expectedValue);
}

TEST(StringCalculatorAddFixture, Multiple_Delimiters)
{
    string input="1[]2///.,@*&^3";
    int expectedValue=6;
    int actualValue=objUnderTest->Add(input);
    ASSERT_EQ(actualValue,expectedValue);
}

TEST(StringCalculatorAddFixture, Multiple_Multicharacter_Delimiter)
{
    string input="1[**]&&&{###}2%%****3";
    int expectedValue=6;
    int actualValue=objUnderTest->Add(input);
    ASSERT_EQ(actualValue,expectedValue);
}
