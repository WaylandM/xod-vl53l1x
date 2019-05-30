
struct State {
};

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
        // The node responds only if there is an input pulse
    if (!isInputDirty<input_UPD>(ctx))
        return;

    // Get a pointer to the `VL53L1X` class instance
    auto sensor = getValue<input_DEV>(ctx);
    sensor->read();

    emitValue<output_RNG>(ctx,sensor->ranging_data.range_mm);
    emitValue<output_PSCR>(ctx,sensor->ranging_data.peak_signal_count_rate_MCPS);
    emitValue<output_ACR>(ctx,sensor->ranging_data.ambient_count_rate_MCPS);
    emitValue<output_STAT>(ctx,sensor->ranging_data.range_status);
    emitValue<output_DONE>(ctx,1);
}
