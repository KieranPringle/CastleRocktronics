#include "switched_multiple.hpp"

void SwitchedMultiple::step() {
  outputs[OUTPUT_1].value = inputs[INPUT_1].value;
  outputs[OUTPUT_2].value =
      switchUp(SWITCH_1) ? outputs[OUTPUT_1].value : inputs[INPUT_2].value;
  outputs[OUTPUT_3].value =
      switchUp(SWITCH_2) ? outputs[OUTPUT_2].value : inputs[INPUT_3].value;
  outputs[OUTPUT_4].value =
      switchUp(SWITCH_3) ? outputs[OUTPUT_3].value : inputs[INPUT_4].value;
};

bool SwitchedMultiple::switchUp(Switches switchID) {
  return params[switchID].value > 0.5;
};