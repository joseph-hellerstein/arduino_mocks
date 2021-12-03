#include "SoftwareSerial.h"
#include <string>
#include <iostream>
#include <random>
#include "Arduino.h"

std::random_device rd;
std::mt19937 mt(rd());
std::uniform_int_distribution<double> dist(0, 1.0);

SoftwareSerial::SoftwareSerial(int rxPin, int txPin) {
    arduino_mock.update_pin_mode(rxPin, INPUT);
    arduino_mock.update_pin_mode(txPin, OUTPUT);
};

void SoftwareSerial::begin(int speed) {
    cout << "Opening SoftwareSerial at speed " + std::to_string(speed);
    return;
}

bool SoftwareSerial::available() {
    if (dist(mt) < 0.5) {
        return TRUE;
    }
    else {
        return FALSE;
    }
}

char SoftwareSerial::read() {
    return SOFTWARE_SERIAL_READ;
}

void SoftwareSerial::print(std::string msg) {
    cout << msg;
}

void SoftwareSerial::print(char msg) {
    cout << std::to_string(msg);
}

void SoftwareSerial::print(int msg) {
    cout << std::to_string(msg);
}

void SoftwareSerial::print(long msg) {
    cout << std::to_string(msg);
}

void SoftwareSerial::println(int msg) {
    this->print(std::to_string(msg));
    cout << "\n";
}

void SoftwareSerial::println(long msg) {
    this->print(std::to_string(msg));
    cout << "\n";
}

void SoftwareSerial::println(char msg) {
    this->print(std::to_string(msg));
    cout << "\n";
}

void SoftwareSerial::println(std::string msg) {
    this->print(msg);
    cout << "\n";
}
