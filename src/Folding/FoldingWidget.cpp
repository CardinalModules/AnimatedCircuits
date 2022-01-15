/**
 * @file FoldingWidget.cpp
 * @author Animated Circuits
 * @brief  wave folding widget
 * @version 2.0
 * @date December 2021
 * 
 * @copyright See License file
 * 
 */

#include "Folding.hpp"
#include "../UIControls.hpp"

using namespace UIControls;

/// No Specific UI controls

struct FoldingWidget: ModuleWidget { 

	FoldingWidget(Folding *module) : ModuleWidget(module)
	{
		setPanel(SVG::load(asset::plugin(pluginInstance, "res/FoldingLight.svg")));

		// addChild(createWidget<ScrewSilver>(Vec(15, 0)));
		addChild(createWidget<ScrewSilver>(Vec(box.size.x-30, 0)));
		addChild(createWidget<ScrewSilver>(Vec(15, 365)));
		// addChild(createWidget<ScrewSilver>(Vec(box.size.x-30, 365)));

		addParam(createParamCentered<TriSineSwitch>(Vec(box.size.x/2.f, 41.5), module, Folding::SHAPE_TYPE_PARAM));

		addParam(createParamCentered<BigBlueKnob>(Vec(box.size.x/2.f, 93.9f), module, Folding::DEPTH_PARAM));
		addParam(createParamCentered<BigWhiteKnob>(Vec(box.size.x/2.f, 204.4f), module, Folding::OFFSET_PARAM));

		addParam(createParamCentered<Trimpot>(Vec(box.size.x/2.f, 138.5f), module, Folding::DEPTH_CV_PARAM));
		addParam(createParamCentered<Trimpot>(Vec(box.size.x/2.f, 249.5f), module, Folding::OFFSET_CV_PARAM));

		addParam(createParam<BipolarSwitch>(Vec(13.5, 267), module, Folding::DEPTH_CV_BIPOLAR_PARAM));
		addParam(createParam<BipolarSwitch>(Vec(48.5, 267), module, Folding::OFFSET_CV_BIPOLAR_PARAM));

		addInput(createInput<LightPort>(Vec(11, 298), module, Folding::DEPTH_CV_INPUT));
		addInput(createInput<LightPort>(Vec(47, 298), module, Folding::OFFSET_CV_INPUT));
	
		addInput(createInput<LightPort>(Vec(11, 330), module, Folding::IN_INPUT));
		addOutput(createOutput<LightPort>(Vec(47, 330), module, Folding::MAIN_OUTPUT));
	}
};

Model *model_AC_Folding = createModel<Folding, FoldingWidget>(SlugFolding);


