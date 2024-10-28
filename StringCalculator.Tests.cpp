#include "StringCalculator.h"
#include <gtest/gtest.h>

TEST(string_calculator_add, when_passed_a_single_number_returns_0_for_empty_string)
{
  //Arrange
  StringCalculator objUnderTest;
  string input="";
  int expectedValue=0;
  //Act
  int actualValue=objUnderTest.Add(input);
  //ASSERT
  ASSERT_EQ(actualValue, expectedValue);
}

TEST(string_calculator_add, when_passed_a_single_number_returns_0_for_zero)
{
  StringCalculator objUnderTest;
  string input="0";
  int expectedValue=0;
  int actualValue=objUnderTest.Add(input);
  ASSERT_EQ(actualValue, expectedValue);
}

TEST(string_calculator_add, when_passed_a_single_number_returns_1_for_one)
{
  StringCalculator objUnderTest;
  string input="1";
  int expectedValue=1;
  int actualValue=objUnderTest.Add(input);
  ASSERT_EQ(actualValue, expectedValue);
}

TEST(string_calculator_add, when_passed_two_comma_delimited_numbers)
{
  StringCalculator objUnderTest;
  string input="1,2";
  int expectedValue=3;
  int actualValue=objUnderTest.Add(input);
  ASSERT_EQ(actualValue, expectedValue);
}

TEST(string_calculator_add, when_passed_multiple_comma_delimited_numbers)
{
  StringCalculator objUnderTest;
  string input="1,2,3";
  int expectedValue=6;
  int actualValue=objUnderTest.Add(input);
  ASSERT_EQ(actualValue, expectedValue);
}

TEST(string_calculator_add, when_delimited_with_newline_and_comma)
{
  StringCalculator objUnderTest;
  string input="1\n2,3";
  int expectedValue=6;
  int actualValue=objUnderTest.Add(input);
  ASSERT_EQ(actualValue, expectedValue);
}

TEST(string_calculator_add, when_passed_a_delimiter)
{
  StringCalculator objUnderTest;
  string input="//;\n1;2";
  int expectedValue=3;
  int actualValue=objUnderTest.Add(input);
  ASSERT_EQ(actualValue, expectedValue);
}

TEST(string_calculator_add, when_passed_negative_number)
{
  StringCalculator objUnderTest;
  string input="1,-2,-3";
  string expectedValue="Negatives not allowed: -2,-3";
  ASSERT_THROW({
      try {
          objUnderTest.Add(input);
      } catch (const std::invalid_argument& e) {
          ASSERT_EQ(e.what(), expectedValue); // Compare the exception message
          throw; // Re-throw the exception to pass the ASSERT_THROW check
      }
  }, std::invalid_argument);
}

TEST(string_calculator_add, when_passed_numbers_over_1000)
{
  StringCalculator objUnderTest;
  string input="1,5000,2";
  int expectedValue=3;
  int actualValue=objUnderTest.Add(input);
  ASSERT_EQ(actualValue, expectedValue);
}

TEST(string_calculator_add, when_passed_multicharacter_delimiter)
{
  StringCalculator objUnderTest;
  string input="1*****\n2****3";
  int expectedValue=6;
  int actualValue=objUnderTest.Add(input);
  ASSERT_EQ(actualValue, expectedValue);
}

TEST(string_calculator_add, when_passed_multiple_delimiters)
{
  StringCalculator objUnderTest;
  string input="1[]2///.,@*&^3";
  int expectedValue=6;
  int actualValue=objUnderTest.Add(input);
  ASSERT_EQ(actualValue, expectedValue);
}

TEST(string_calculator_add, when_passed_multiple_multicharacter_delimiters)
{
  StringCalculator objUnderTest;
  string input="1[**]&&&{###}2%%****3";
  int expectedValue=6;
  int actualValue=objUnderTest.Add(input);
  ASSERT_EQ(actualValue, expectedValue);
}
