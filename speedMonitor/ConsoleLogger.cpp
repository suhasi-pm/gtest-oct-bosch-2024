#include "ILogger.h"
using namespace std;

class ConsoleLogger:public ILogger
{
   public:
     void write(const string& message)
     {
         cout << message;
    }
};
