#include "rack.hpp"

using namespace rack;

struct SwitchedMultiple : Module {
  enum Switches { SWITCH_1, SWITCH_2, SWITCH_3, NUM_SWITCHES };

  enum Inputs { INPUT_1, INPUT_2, INPUT_3, INPUT_4, NUM_INPUTS };

  enum Outputs { OUTPUT_1, OUTPUT_2, OUTPUT_3, OUTPUT_4, NUM_OUTPUTS };

  SwitchedMultiple() : Module(NUM_SWITCHES, NUM_INPUTS, NUM_OUTPUTS, 0) {}

  void step() override;

 private:
  bool switchUp(Switches switchId);
};