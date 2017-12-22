#include "rack.hpp"

using namespace rack;

extern Plugin *plugin;

struct Crossfader : Module {

  enum Params {
    FADER,
    CV_TRIMPOT,
    EXP_LIN_TRIMPOT,
    NUM_PARAMS
	};

  enum Inputs {
    INPUT_1,
    INPUT_2,
    FADER_CV,
    NUM_INPUTS
  };
    
  enum Outputs {
    OUTPUT,
    NUM_OUTPUTS
  };

  Crossfader() : Module(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, 0) {}
    
  void step() override;

private:
  float getFinalGainFactor();  
  float getTrimpotAdjustedCV();
  float getExpLinTrimpotAdjustedGain(float gain);
};