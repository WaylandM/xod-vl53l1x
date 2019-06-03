
struct State {
};

{{ GENERATED_CODE }}

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
        if(!sensor->setDistanceMode(VL53L1X::Short)) {
            emitValue<output_ERR>(ctx, 1);
            return;
        }
    }

    if(mode==1)
    {
        if(!sensor->setDistanceMode(VL53L1X::Medium)) {
            emitValue<output_ERR>(ctx, 1);
            return;
        }
    }

    if(mode==2)
    {
        if(!sensor->setDistanceMode(VL53L1X::Long)) {
            emitValue<output_ERR>(ctx, 1);
            return;
        }
    }




    
    emitValue<output_OK>(ctx,1);
}
