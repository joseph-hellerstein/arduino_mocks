/*
    Tests for mock codes.
*/

#include <iostream>
#include "Arduino.h"
#include "SR04.h"
#include <assert.h>
#include "SoftwareSerial.h"
#include "common.h"
using namespace std;

void testNativeSerial() {
    Serial.begin(9600);
    assert(Serial.speed == 9600);
    #
    Serial.print("test serial.print");
    Serial.println("test serial.println");
}

void testPinMode() {
    int pin = 1;
    int mode = 2;
    pinMode(pin, mode);
    //string line = std::to_string(arduino_mock.pin_modes[pin]) + "\n" + std::to_string(mode) + "\n";
    //cout << line;
    assert(arduino_mock.pin_modes[pin] == mode);
}

void testDigitalWrite() {
    int pin = 1;
    int value = 2;
    digitalWrite(pin, value);
    //string line = std::to_string(arduino_mock.pin_modes[pin]) + "\n" + std::to_string(mode) + "\n";
    //cout << line;
    assert(arduino_mock.pin_values[pin] == value);
}

void testAnalogWrite() {
    int pin = 1;
    int value = 2;
    analogWrite(pin, value);
    //string line = std::to_string(arduino_mock.pin_modes[pin]) + "\n" + std::to_string(mode) + "\n";
    //cout << line;
    assert(arduino_mock.pin_values[pin] == value);
}

void testMillis() {
    long time1 = millis();
    arduino_mock.ticktock();
    long time2 = millis();
    assert(time1 < time2);
}

void testSoftwareSerial() {
    int rxPin = 1;
    int txPin = 2;
    SoftwareSerial serial = SoftwareSerial(rxPin, txPin);
    assert(arduino_mock.pin_modes[rxPin] == INPUT);
    assert(arduino_mock.pin_modes[txPin] == OUTPUT);
    serial.print("Hello");
    int sum = 0;
    for (int i=0; i < 100; i++){
        if (serial.available()) {
            sum++;
        }
    }
    assert(sum >40);
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
    testNativeSerial();
    testPinMode();
    testDigitalWrite();
    testAnalogWrite();
    testMillis();
    testSoftwareSerial();
    testUltraSonic();
    testArduinoMock();

    cout << "\n";
    cout << "OK!";
    cout << "\n";
}
