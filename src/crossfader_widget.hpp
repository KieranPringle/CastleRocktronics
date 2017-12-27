#include "rack.hpp"
#include "crossfader.hpp"

using namespace rack;

extern Plugin *plugin;

struct CrossfaderWidget : ModuleWidget {
    CrossfaderWidget();

private:
    int moduleWidth;
    
    void placeGuiElements();
    void placeAudioInputs(int x, int y, int verticalSpacing);
    void placeCvInput(int x, int y);
    void placeOutput(int x, int y);
    void placeSlider(int x, int y);
    void placeTrimpots(int x, int y, int horizontalSpacing);
    void placeScrews();
};