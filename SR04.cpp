/*
    Mocks for arduino interfaces
*/
#include "SR04.h"
#include <string>
#include <vector>
using namespace std;

SR04::SR04(int echo_pin, int trig_pin) {
    this->echo_pin = echo_pin;
    this->trig_pin = trig_pin;
    this->count = 0;
};

long SR04::Distance() {
    this->count++;
    return 10*count;
};
