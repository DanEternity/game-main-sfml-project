#include "ui-base-elements.h"

UI_text * s_text;
UI_TextObject * wpn_text;
UI_TextObject * mod_eff_desc_text;

void initAllSamples()
{
	s_text = new UI_text(fontArial);
	wpn_text = new UI_TextObject;
	mod_eff_desc_text = new UI_TextObject;
}
