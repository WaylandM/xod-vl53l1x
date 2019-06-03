
struct State {
};

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    // The node responds only if there is an input pulse
    if (!isInputDirty<input_UPD>(ctx))
        return;

    // Get a pointer to the `VL53L1X` class instance
    auto sensor = getValue<input_DEV>(ctx);

    VL53L1X::DistanceMode mode = sensor->getDistanceMode();

    switch (mode)
    {
        case VL53L1X::Short:
            emitValue<output_DM>(ctx,0);
            break;

        case VL53L1X::Medium:
            emitValue<output_DM>(ctx,1);
            break;

        case VL53L1X::Long:
            emitValue<output_DM>(ctx,2);
            break;

        default:
            emitValue<output_DM>(ctx,3);
    }
    emitValue<output_DONE>(ctx,1);
}
