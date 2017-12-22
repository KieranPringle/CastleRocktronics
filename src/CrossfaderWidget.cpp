#include "CrossfaderWidget.hpp"

CrossfaderWidget::CrossfaderWidget() {
    this->moduleWidth = 8 * RACK_GRID_WIDTH;

    Crossfader *module = new Crossfader();
    setModule(module);
    box.size = Vec(moduleWidth, RACK_GRID_HEIGHT);
    
    {
        SVGPanel *panel = new SVGPanel();
        panel->box.size = box.size;
        panel->setBackground(SVG::load(assetPlugin(plugin, "res/crossfader.svg")));
        addChild(panel);
    }
    
    placeGuiElements();
};

void CrossfaderWidget::placeGuiElements(){
    int y = (RACK_GRID_HEIGHT / 2) - 15;
    int x = (moduleWidth / 3) - 35;
    int horizontalSpacing = ((moduleWidth / 3) * 2) - 2;
    placeCvInput(x, y);
    placeOutput(x + horizontalSpacing, y);

    placeTrimpots(x + 5, (RACK_GRID_HEIGHT / 3)*2 - 15, horizontalSpacing);

    x = (moduleWidth / 2) - 15;
    y = (RACK_GRID_HEIGHT / 6) - 17;
    int verticalSpacing = (RACK_GRID_HEIGHT / 3) * 2;
    placeAudioInputs(x, y, verticalSpacing);
  
    x = (moduleWidth / 2) - 9;
    y = (RACK_GRID_HEIGHT / 2) - (RACK_GRID_HEIGHT/32)*5;
    placeSlider(x, y);

    placeScrews();
}

void CrossfaderWidget::placeAudioInputs(int x, int startingY, int spacing){
   for (int i = 0; i != Crossfader::FADER_CV; i++ ){
        Crossfader::Inputs input = static_cast<Crossfader::Inputs>(i);
        int y = startingY + (spacing * i);

        addInput(createInput<PJ3410Port>(Vec(x, y), module, input));
    }
}

void CrossfaderWidget::placeOutput(int x, int y){
    addOutput(createOutput<PJ3410Port>(Vec(x, y), module, Crossfader::OUTPUT));
}

void CrossfaderWidget::placeCvInput(int x, int y){
    addInput(createInput<PJ3410Port>(Vec(x, y), module, Crossfader::FADER_CV));
}

void CrossfaderWidget::placeSlider(int x, int y){
    addParam(createParam<BefacoSlidePot>(Vec(x, y), module, Crossfader::FADER, -10.0f, 10.0f, 0.0f));
}

void CrossfaderWidget::placeTrimpots(int x, int y, int horizontalSpacing){
    addParam(createParam<Trimpot>(Vec(x, y), module, Crossfader::CV_TRIMPOT, -2.0f, 2.0f, 0.0f));
    addParam(createParam<Trimpot>(Vec(x + horizontalSpacing, y), module, Crossfader::EXP_LIN_TRIMPOT, 0.0f, 1.0f, 0.0f));
}

void CrossfaderWidget::placeScrews(){
    addChild(createScrew<ScrewSilver>(Vec(RACK_GRID_WIDTH, 0)));
    addChild(createScrew<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, 0)));
    addChild(createScrew<ScrewSilver>(Vec(RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));
    addChild(createScrew<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));
}