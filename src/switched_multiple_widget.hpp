#include "rack.hpp"

using namespace rack;

extern Plugin *plugin;

struct SwitchedMultipleWidget : ModuleWidget {
  SwitchedMultipleWidget();

 private:
  int moduleWidth;

  void placeGUIElements();
  void placeInputs(int startX, int startY, int spacing);
  void placeOutputs(int startX, int startY, int spacing);
  void placeSwitches(int startX, int startY, int spacing);
  void placeScrews();
};