#include <string>
#include <vector>
using namespace std;

#define TRUE 1==1
#define FALSE 1==0

#define NUM_PIN 60

// Mocked values
#define SOFTWARE_SERIAL_READ 'b'

/* Arduino defines for mock */
#define INPUT 1
#define OUTPUT 2
#define LOW 1
#define HIGH 2

class Serial {
    public:
        int speed;
        Serial();
        void begin(int speed);
        void print(std::string msg);
        void println(std::string msg);

};

void pinMode(int pin, int mode);
void digitalWrite(int pin, int value);
void analogWrite(int pin, int value);
long millis();   

/* ------------------*/
/* SoftwareSerial    */
/* ------------------*/
class SoftwareSerial {

    public:
        int txPin;
        int rxPin;

        SoftwareSerial(int rxPin, int txPin);
        void print(string msg);
        bool available();
        char read();
};

/* UltraSonic */
class SR04 {
    
    public:
        int echo_pin;
        int trig_pin;

        SR04(int echo_pin, int trig_pin);
        int Distance();
};

/* AdruinoMock */
class ArduinoMock {

    public:
        long time;
        int pin_modes[NUM_PIN];
        int pin_values[NUM_PIN];

        ArduinoMock();
        void update_pin_mode(int pin, int value);
        void update_pin_value(int pin, int mode);
        void ticktock(); /* Updates the clock */
        long getTime();
        void record(string msg); /* records an action */
};

ArduinoMock * getAdrduinoMock();