#include "SoftwareSerial.h"
#include <string>
#include <iostream>
#include "Arduino.h"


SoftwareSerial::SoftwareSerial(int rxPin, int txPin) {
    arduino_mock.update_pin_mode(rxPin, INPUT);
    arduino_mock.update_pin_mode(txPin, OUTPUT);
};

void SoftwareSerial::begin(int speed) {
    cout << "Opening SoftwareSerial at speed " + std::to_string(speed);
    return;
}

void SoftwareSerial::print(string msg) {
    cout << "Software serial: " + msg;
}

void SoftwareSerial::println(string msg) {
    string line = "Software serial: " + msg + "\n";
    cout << line;
}

bool SoftwareSerial::available() {
    return TRUE;
}

char SoftwareSerial::read() {
    return SOFTWARE_SERIAL_READ;
}
