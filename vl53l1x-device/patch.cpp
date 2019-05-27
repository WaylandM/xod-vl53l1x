// Tell XOD where it could download the library:
#pragma XOD require "https://github.com/pololu/vl53l1x-arduino"

//Include C++ libraries
{{#global}}
#include <VL53L1X.h>
#include <Wire.h>
{{/global}}


// Reserve memory to store an instance of the class,
// and create the instance later:
struct State {
    uint8_t mem[sizeof(VL53L1X)];
};

// Define our custom type as a pointer on the class instance.
using Type = VL53L1X*;


{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    // It should be evaluated only once on the first (setup) transaction
    if (!isSettingUp())
        return;

    auto state = getState(ctx);

    // Create a new object in the memory area reserved previously.
    Type sensor = new (state->mem) VL53L1X();
    //address
    //timeout

    emitValue<output_DEV>(ctx, sensor);
}
