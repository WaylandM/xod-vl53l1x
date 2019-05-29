
struct State {
};

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    // The node responds only if there is an input pulse
    if (!isInputDirty<input_UPD>(ctx))
        return;

    // Get a pointer to the `VL53L1X` class instance
    auto sensor = getValue<input_DEV>(ctx);
    auto mode = getValue<input_DM>(ctx);

    if(mode == "S") {
        if(!sensor->setDistanceMode(VL53L1X::Short)) {
            emitValue<output_ERR>(ctx, 1);
            return;
        }
    } else if(mode == "M") {
        if(!sensor->setDistanceMode(VL53L1X::Medium)) {
            emitValue<output_ERR>(ctx, 1);
            return;
        }
    } else if(mode == "L") {
        if(!sensor->setDistanceMode(VL53L1X::Long)) {
            emitValue<output_ERR>(ctx, 1);
            return;
    } else {
            emitValue<output_ERR>(ctx, 1);
            return;
        }

    emitValue<output_OK>(ctx,1);
}
