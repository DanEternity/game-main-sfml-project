#include "ui-base-elements.h"

UI_text * s_text;
UI_TextObject * wpn_text;
UI_TextObject * mod_eff_desc_text;

void initAllSamples()
{
	s_text = new UI_text(fontArial);

	wpn_text = new UI_TextObject();
	wpn_text->init(fontArial, 400, 400);
	wpn_text->lineSpacing = 36;

	mod_eff_desc_text = new UI_TextObject();
	mod_eff_desc_text->init(fontArial, 480, 270);
	mod_eff_desc_text->setCharSize(16);
	mod_eff_desc_text->lineSpacing = 30;
}
