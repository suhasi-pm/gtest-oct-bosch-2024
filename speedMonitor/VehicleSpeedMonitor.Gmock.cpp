#include "VehicleSpeedMonitor.h"
#include <gmock/gmock.h>
using testing::StrEq; //Built In Matcher
using testing::Return; //Built in Action
using testing::_;

class MockLogger:public ILogger
{
   public:
      MOCK_METHOD(void, write, (const string& message), (override));
};

class MockCommunicator:public IMessageCommunicator
{
   public:
      MOCK_METHOD(int, pushMessage, (const string& message), (override));
};

class MockSpeedSensor:public ISpeedSensor
{
   public:
      MOCK_METHOD( int , getCurrentSpeed, (), (override));
};

TEST(VehicleSpeedMonitorTestSuite, LoggerInteractionTesting)
{
   SpeedMonitor objUnderTest{150};
   MockCommunicator communicator;
   MockSpeedSensor speedSensor;
   MockLogger logger;
   EXPECT_CALL(logger, write(StrEq("_speedThreshold value must be in the range {1-100} 150")));
   objUnderTest.monitor(&communicator, &speedSensor, &logger);
}

TEST(VehicleSpeedMonitorTestSuite, InteractionTesting)
{
   SpeedMonitor objUnderTest{40};
   MockCommunicator communicator;
   MockSpeedSensor speedSensor;
   MockLogger logger;
   EXPECT_CALL(speedSensor, getCurrentSpeed()).WillOnce(Return(60));    // Speed below threshold  
   EXPECT_CALL(communicator, pushMessage(_)).WillOnce(Return(450));     // No alert expected
   EXPECT_CALL(logger, write(_)).Times(2);                              // Log is expected
   objUnderTest.monitor(&communicator,&speedSensor,&logger);
}
