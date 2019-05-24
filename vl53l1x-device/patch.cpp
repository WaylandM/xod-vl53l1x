// Tell XOD where it could download the library:
#pragma XOD require "https://github.com/pololu/vl53l1x-arduino"

//Include C++ libraries
{{#global}}
#include <VL53L1X.h>
#include <Wire.h>
{{/global}}


struct State {
};

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    //auto inValue = getValue<input_IN>(ctx);
    //emitValue<output_OUT>(ctx, inValue);
}
