
node {

    void evaluate(Context ctx) {
        // The node responds only if there is an input pulse
        if (!isInputDirty<input_UPD>(ctx))
            return;
        // Get a pointer to the `VL53L1X` class instance
        auto sensor = getValue<input_DEV>(ctx);
        sensor->setROI(getValue<input_X>(ctx), getValue<input_Y>(ctx));
        emitValue<output_DONE>(ctx,1);
    }
}
