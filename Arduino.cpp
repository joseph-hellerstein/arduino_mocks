/*
    Mocks for arduino interfaces
*/
#include <iostream>
#include <vector>
#include "Arduino.h"
using namespace std;

/*------------------------- Globals ----------------*/
ArduinoMock arduino_mock = ArduinoMock();
NativeSerial Serial = NativeSerial();
/*-------------------------------------------------*/


/* ------------------*/
/* Native Serial interface  */
/* ------------------*/
NativeSerial::NativeSerial(){
    return;
}

void NativeSerial::begin(int speed) {
    this->speed = speed;
    arduino_mock.record("Set serial speed.");
}

void NativeSerial::print(std::string msg) {
    cout << msg;
}

void NativeSerial::print(char msg) {
    cout << std::to_string(msg);
}

void NativeSerial::print(int msg) {
    cout << std::to_string(msg);
}

void NativeSerial::print(long msg) {
    cout << std::to_string(msg);
}

void NativeSerial::println(int msg) {
    this->print(std::to_string(msg));
    cout << "\n";
}

void NativeSerial::println(long msg) {
    this->print(std::to_string(msg));
    cout << "\n";
}

void NativeSerial::println(char msg) {
    this->print(std::to_string(msg));
    cout << "\n";
}

void NativeSerial::println(std::string msg) {
    this->print(msg);
    cout << "\n";
}


/* ------------------*/
/* Misc Functions    */
/* ------------------*/

void pinMode(int pin, int mode) {
    arduino_mock.update_pin_mode(pin, mode);
}

void digitalWrite(int pin, int value) {
    arduino_mock.update_pin_value(pin, value);
}

void analogWrite(int pin, int value) {
    arduino_mock.update_pin_value(pin, value);
}

long millis() {
    return arduino_mock.getTime();
};

void delay(int duration) {
    arduino_mock.time += duration;
};

/* AdruinoMock */
ArduinoMock::ArduinoMock() {
    this->time = 0;
};

void ArduinoMock::update_pin_mode(int pin, int mode) {
    this->pin_modes[pin] = mode;
};

void ArduinoMock::update_pin_value(int pin, int value) {
    this->pin_values[pin] = value;
};
        
void ArduinoMock::ticktock() {
    this->time++;
};
        
long ArduinoMock::getTime() {
    return this->time;
};

void ArduinoMock::record(string msg) {
    this->ticktock();
    cout << this->getTime();
    cout << ":  ";
    cout << msg;
    cout << "\n";
}
