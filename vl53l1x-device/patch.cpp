// Tell XOD where it could download the library:
#pragma XOD require "https://github.com/WaylandM/vl53l1x-arduino-mtw"

//Include C++ libraries
#include <VL53L1X.h>
#include <Wire.h>

node {
    meta {
        // Define our custom type as a pointer on the class instance.
        using Type = VL53L1X*;
    }

    // Create an object of the class VL53L1X
    VL53L1X sensor = VL53L1X();

    void evaluate(Context ctx) {
        // It should be evaluated only once on the first (setup) transaction
        if (!isSettingUp())
            return;

        Wire.begin();
        Wire.setClock(400000); // use 400 kHz I2C

        sensor.setTimeout(getValue<input_TO>(ctx));

        // Attempt to initialize VL53L1X module; if attempt fails emit error
        if (!sensor.init()) {
            raiseError(ctx);
            return;
        }

        emitValue<output_DEV>(ctx, &sensor);
    }
}

