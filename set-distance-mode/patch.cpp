node {
    void evaluate(Context ctx) {
        // The node responds only if there is an input pulse
        if (!isInputDirty<input_UPD>(ctx))
            return;

        // Get a pointer to the `VL53L1X` class instance
        auto sensor = getValue<input_DEV>(ctx);
        // get distance mode
        auto mode = getValue<input_DM>(ctx);

        if(mode==0)
        {
            if(!sensor->setDistanceMode(VL53L1XMTW::Short)) {
                raiseError(ctx);
                return;
            }
        }

        if(mode==1)
        {
            if(!sensor->setDistanceMode(VL53L1XMTW::Medium)) {
                raiseError(ctx);
                return;
            }
        }

        if(mode==2)
        {
            if(!sensor->setDistanceMode(VL53L1XMTW::Long)) {
                raiseError(ctx);
                return;
            }
        }
        emitValue<output_OK>(ctx,1);
    }
}



