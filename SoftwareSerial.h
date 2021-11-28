#include <string>
using namespace std;

class SoftwareSerial {

    public:
        int txPin;
        int rxPin;

        SoftwareSerial(int rxPin, int txPin);
        void begin(int speed);
        void print(string msg);
        void println(string msg);
        bool available();
        char read();
};
