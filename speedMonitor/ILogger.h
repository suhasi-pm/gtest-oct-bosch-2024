#include <string>
using namespace std;
class ILogger
{
    public:
     virtual void write(const string& message) = 0;
};
