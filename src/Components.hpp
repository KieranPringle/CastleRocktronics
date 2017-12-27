#include "rack.hpp"

using namespace rack;

extern Plugin *plugin;
   
struct MiniJack : SVGPort {
    MiniJack() {
	    background->svg = SVG::load(assetPlugin(plugin, "res/components/minijack.svg"));
	    background->wrap();
	    box.size = background->box.size;
    }
};
