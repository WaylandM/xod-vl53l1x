
struct State {
};

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    // The node responds only if there is an input pulse
    if (!isInputDirty<input_UPD>(ctx))
        return;

    // Get a pointer to the `VL53L1X` class instance
    auto sensor = getValue<input_DEV>(ctx);

    DistanceMode mode = sensor->getDistanceMode();

    switch (mode)
    {
        case Short:
            emitValue<output_DM>(ctx,"S");
            break;

        case Medium:
            emitValue<output_DM>(ctx,"M");
            break;

        case Long:
            emitValue<output_DM>(ctx,"L");
            break;

        default:
            emitValue<output_DM>(ctx,"?");
    }
    emitValue<output_DONE>(ctx,1);
}
