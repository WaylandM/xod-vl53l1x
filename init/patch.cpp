
struct State {
};

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    // The node responds only if there is an input pulsei
    if (!isInputDirty<input_INIT>(ctx))
        return;

    Wire.begin();
    Wire.setClock(400000); // use 400 kHz I2C

    // Get a pointer to the `VL53L1X` class instance
    auto sensor = getValue<input_DEV>(ctx);

    sensor->setTimeout(getValue<input_T>(ctx));

    // Attempt to initialize VL53L1X module; if attempt fails emit pulse from error port
    if (!sensor->init()) {
        emitValue<output_ERR>(ctx, 1);
        return;
    }

    // Pulse that module initialized successfully
    emitValue<output_OK>(ctx, 1);
}
