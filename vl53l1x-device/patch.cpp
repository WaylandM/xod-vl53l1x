// Tell XOD where it could download the library:
#pragma XOD require "https://github.com/WaylandM/vl53l1x-arduino-mtw"

//Include C++ libraries
#include <VL53L1XMTW.h>
#include <Wire.h>

node {
    meta {
        // Define our custom type as a pointer on the class instance.
        using Type = VL53L1XMTW*;
    }

    // Create an object of the class VL53L1XMTW
    VL53L1XMTW sensor = VL53L1XMTW();

    void evaluate(Context ctx) {
        // It should be evaluated only once on the first (setup) transaction
        if (!isSettingUp())
            return;

        emitValue<output_DEV>(ctx, &sensor);
    }
}

