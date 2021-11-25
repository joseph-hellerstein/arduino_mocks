/*
    Tests for mock codes.
*/

#include <iostream>
#include "arduino_mocks.h"
#include <assert.h>
using namespace std;

ArduinoMock * p_arduino_mock;

void testSerial() {
    Serial serial = Serial();
    serial.begin(9600);
    assert(serial.speed == 9600);
    #
    serial.print("test serial.print");
    serial.println("test serial.println");
}

void testPinMode() {
    int pin = 1;
    int mode = 2;
    pinMode(pin, mode);
    //string line = std::to_string(p_arduino_mock->pin_modes[pin]) + "\n" + std::to_string(mode) + "\n";
    //cout << line;
    assert(p_arduino_mock->pin_modes[pin] == mode);
}

void testDigitalWrite() {
    int pin = 1;
    int value = 2;
    digitalWrite(pin, value);
    //string line = std::to_string(p_arduino_mock->pin_modes[pin]) + "\n" + std::to_string(mode) + "\n";
    //cout << line;
    assert(p_arduino_mock->pin_values[pin] == value);
}

void testAnalogWrite() {
    int pin = 1;
    int value = 2;
    analogWrite(pin, value);
    //string line = std::to_string(p_arduino_mock->pin_modes[pin]) + "\n" + std::to_string(mode) + "\n";
    //cout << line;
    assert(p_arduino_mock->pin_values[pin] == value);
}

void testMillis() {
    long time1 = millis();
    p_arduino_mock->ticktock();
    long time2 = millis();
    assert(time1 < time2);
}

void testSoftwareSerial() {
    int rxPin = 1;
    int txPin = 2;
    SoftwareSerial serial = SoftwareSerial(rxPin, txPin);
    assert(p_arduino_mock->pin_modes[rxPin] == INPUT);
    assert(p_arduino_mock->pin_modes[txPin] == OUTPUT);
    serial.print("Hello");
    bool value = serial.available();
    assert(value);
    char byte = serial.read();
    assert(byte == SOFTWARE_SERIAL_READ);
}

void testUltraSonic() {
    assert(TRUE);
}


void testArduinoMock() {
    assert(TRUE);
}

int main() {
    p_arduino_mock = getAdrduinoMock();
    testSerial();
    testPinMode();
    testDigitalWrite();
    testAnalogWrite();
    testMillis();
    testSoftwareSerial();
    testUltraSonic();
    testArduinoMock();
    #
    cout << "\n";
    cout << "OK!";
    cout << "\n";
}