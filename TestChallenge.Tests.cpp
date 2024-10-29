#include "TestChallenge.h"
#include <gtest/gtest.h>
#include <tuple>
using namespace std;

class TestChallengeFixture:public testing::Test
{
  protected:
    int result;
  void SetUp() override
  {
      result = 0;
  }
};


TEST_F(TestChallengeFixture, AddTwoNumbers)
{
    int expectedValue = 9;
    add(3, 6, result);
    ASSERT_EQ(result, expectedValue);
}
