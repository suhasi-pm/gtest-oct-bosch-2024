#include "StringCalculator.h"
#include <gtest/gtest.h>

TEST(string_calculator_add, when_passed_a_single_number_returns_0_for_zero)
{
  //Arrange
  StringCalculator objUnderTest;
  sting input="";
  int expectedValue=0;

  //Act
  int actualValue=objUnderTest.Add(input);

  //ASSERT
  ASSERT_EQ(actualValue, expectedValue);
}
