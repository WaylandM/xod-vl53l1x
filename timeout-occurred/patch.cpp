node {
    void evaluate(Context ctx) {
        // The node responds only if there is an input pulse
        if (!isInputDirty<input_UPD>(ctx))
            return;

        // Get a pointer to the `VL53L1X` class instance
        auto sensor = getValue<input_DEV>(ctx);

        emitValue<output_TO>(ctx,sensor->timeoutOccurred());
        emitValue<output_DONE>(ctx,1);

    }

}

