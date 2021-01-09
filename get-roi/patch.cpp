
node {
    void evaluate(Context ctx) {
        // The node responds only if there is an input pulse
        if (!isInputDirty<input_UPD>(ctx))
            return;
        // Get a pointer to the `VL53L1X` class instance
        auto sensor = getValue<input_DEV>(ctx);

        uint16_t x, y;
        sensor->getROIxy(&x, &y);
        emitValue<output_X>(ctx, x);
        emitValue<output_Y>(ctx, y);
        emitValue<output_DONE>(ctx,1);
    }
}
