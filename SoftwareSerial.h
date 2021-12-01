#include <string>
using namespace std;

class SoftwareSerial {

    public:
        int txPin;
        int rxPin;

        SoftwareSerial(int rxPin, int txPin);
        void begin(int speed);
        void print(char msg);
        void print(int msg);
        void print(long msg);
        void print(std::string msg);
        void println(std::string msg);
        void println(long msg);
        void println(int msg);
        void println(char msg);
        bool available();
        char read();
};
