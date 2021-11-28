#ifndef SR04_h
#define SR04_h

#include <string>
#include <vector>
using namespace std;

class SR04 {
    
    public:
        int echo_pin;
        int trig_pin;

        SR04(int echo_pin, int trig_pin);
        long Distance();
};

#endif
