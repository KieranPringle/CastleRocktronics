#include "switched_multiple_widget.hpp"
#include "components.hpp"
#include "switched_multiple.hpp"

SwitchedMultipleWidget::SwitchedMultipleWidget() {
  this->moduleWidth = 6 * RACK_GRID_WIDTH;

  SwitchedMultiple *module = new SwitchedMultiple();
  setModule(module);
  box.size = Vec(moduleWidth, RACK_GRID_HEIGHT);

  {
    SVGPanel *panel = new SVGPanel();
    panel->box.size = box.size;
    panel->setBackground(
        SVG::load(assetPlugin(plugin, "res/switched-multiple.svg")));
    addChild(panel);
  }

  placeGUIElements();
};

void SwitchedMultipleWidget::placeGUIElements() {
  int leftSide = 5;
  int rightSide = moduleWidth - 35;

  int startY = 35;
  int spacing = 40;

  placeInputs(leftSide, startY + spacing, spacing * 2);
  placeOutputs(rightSide, startY, spacing);
  placeSwitches(leftSide, startY + (spacing * 2), spacing * 2);
  placeScrews();
};

void SwitchedMultipleWidget::placeOutputs(int x, int startingY, int spacing) {
  for (int i = 0; i != SwitchedMultiple::NUM_OUTPUTS; i++) {
    SwitchedMultiple::Outputs output =
        static_cast<SwitchedMultiple::Outputs>(i);
    int y = startingY + (spacing * 2 * i);

    addOutput(createOutput<MiniJack>(Vec(x, y), module, output));
    addOutput(createOutput<MiniJack>(Vec(x, y + spacing), module, output));
  }
};

void SwitchedMultipleWidget::placeInputs(int x, int startingY, int spacing) {
  for (int i = 0; i != SwitchedMultiple::NUM_INPUTS; i++) {
    SwitchedMultiple::Inputs input = static_cast<SwitchedMultiple::Inputs>(i);
    int y = startingY + (spacing * i);

    addInput(createInput<MiniJack>(Vec(x, y), module, input));
  }
};

void SwitchedMultipleWidget::placeSwitches(int x, int startingY, int spacing) {
  int xOffset = 8;
  int yOffset = 5;

  for (int i = 0; i != SwitchedMultiple::NUM_SWITCHES; i++) {
    SwitchedMultiple::Switches switchParam =
        static_cast<SwitchedMultiple::Switches>(i);
    int adjustedY = (startingY + yOffset) + (spacing * i);
    int adjustedX = x + xOffset;

    addParam(createParam<CKSS>(Vec(adjustedX, adjustedY), module, switchParam,
                               0.0, 1.0, 0.0));
  }
};

void SwitchedMultipleWidget::placeScrews() {
  addChild(createScrew<ScrewSilver>(Vec(RACK_GRID_WIDTH, 0)));
  addChild(createScrew<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, 0)));
  addChild(createScrew<ScrewSilver>(
      Vec(RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));
  addChild(createScrew<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH,
                                        RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));
}