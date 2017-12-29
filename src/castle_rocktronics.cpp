#include "cubefader_widget.hpp"
#include "switched_multiple_widget.hpp"

// The plugin-wide instance of the Plugin class
Plugin *plugin;

void init(rack::Plugin *p) {
  plugin = p;
  // This is the unique identifier for your plugin
  p->slug = "CastleRocktronics";
#ifdef VERSION
  p->version = TOSTRING(VERSION);
#endif
  p->website = "";
  p->manual = "";

  // For each module, specify the ModuleWidget subclass, manufacturer slug (for
  // saving in patches), manufacturer human-readable name, module slug, and
  // module name
  p->addModel(createModel<SwitchedMultipleWidget>("CastleRocktronics", "CR-V01_SwitchedMultiple", "Switched Multiple", UTILITY_TAG, MULTIPLE_TAG));
  p->addModel(createModel<CubefaderWidget>("CastleRocktronics",
                                           "CR-V02_Cubefader", "Cubefader",
                                           UTILITY_TAG, MIXER_TAG));

  // Any other plugin initialization may go here.
  // As an alternative, consider lazy-loading assets and lookup tables when your
  // module is created to reduce startup times of Rack.
}
