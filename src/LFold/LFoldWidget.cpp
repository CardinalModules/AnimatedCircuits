/**
 * @file LFoldWidget.cpp
 * @author Animated Circuits
 * @brief  LFO with wave folding module widget
 * @version 2.0
 * @date December 2021
 * @copyright See License file
 */

#include "LFold.hpp"
#include "../UIControls.hpp"

using namespace UIControls;

/// No Specific UI controls

struct LFoldWidget: ModuleWidget { 

	LFoldWidget(LFold *module) : ModuleWidget(module)
	{
		setPanel(SVG::load(asset::plugin(pluginInstance, "res/LFoldLight.svg")));

		// addChild(createWidget<ScrewSilver>(Vec(15, 0)));
		addChild(createWidget<ScrewSilver>(Vec(box.size.x-30, 0)));
		addChild(createWidget<ScrewSilver>(Vec(15, 365)));
		// addChild(createWidget<ScrewSilver>(Vec(box.size.x-30, 365)));

		addParam(createParamCentered<BigGreyKnob>(Vec(box.size.x/2.f, 76.f), module, LFold::FREQ_PARAM));

		addParam(createParamCentered<BigBlueKnob>(Vec(box.size.x/2.f, 165.f), module, LFold::FOLD_DEPTH_PARAM));
		addParam(createParamCentered<BigWhiteKnob>(Vec(box.size.x/2.f, 232.f), module, LFold::FOLD_OFFSET_PARAM));	
		addParam(createParamCentered<TriSineSwitch>(Vec(box.size.x/2.f, 113.f), module, LFold::FOLD_SHAPE_TYPE_PARAM));

		addParam(createParam<BipolarSwitch>(Vec(13.5, 267), module, LFold::INPUT_BIPOLAR_PARAM));
		addParam(createParam<BipolarSwitch>(Vec(49, 267), module, LFold::OUTPUT_BIPOLAR_PARAM));
		
		addInput(createInput<LightPort>(Vec(11, 298), module, LFold::IN_INPUT));
		addInput(createInput<LightPort>(Vec(11, 330), module, LFold::SYNC_INPUT));
	
		addOutput(createOutput<LightPort>(Vec(47, 298), module, LFold::MAIN_OUTPUT));
		addOutput(createOutput<LightPort>(Vec(47, 330), module, LFold::LFOLD_OUTPUT));
	}
};

Model *model_AC_LFold = createModel<LFold, LFoldWidget>(SlugLFold);
