#include "Crossfader.hpp"
#include "math.hpp"

void Crossfader::step() {
    float scaling = getFinalGainFactor();

    outputs[OUTPUT].value = crossf(inputs[INPUT_1].value, inputs[INPUT_2].value, scaling);
};

float Crossfader::getTrimpotAdjustedCV(){
    return inputs[FADER_CV].value * params[CV_TRIMPOT].value;
}

float Crossfader::getExpLinTrimpotAdjustedGain(float gain){
    float scalingFactor = 10.0f;
    float expLinAdjusted = powf(scalingFactor, params[EXP_LIN_TRIMPOT].value);
    return powf(gain, expLinAdjusted);
}

float Crossfader::getFinalGainFactor(){
    float inputMin = -10.0f;
    float inputMax = 10.0f;
    float outputMin = 0.0f;
    float outputMax = 1.0f;

    float fader = params[FADER].value;
    float cv = getTrimpotAdjustedCV();
    float summedGains = clampf(fader + cv, inputMin, inputMax);

    float scaledGain = rescalef(summedGains, inputMin, inputMax, outputMin, outputMax);
    return getExpLinTrimpotAdjustedGain(scaledGain);
}