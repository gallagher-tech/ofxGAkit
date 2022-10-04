#pragma once
#include "ofMain.h"
#include "ga/render.h"
#include "ga/graph/node.h"
#include "ga/graph/components/bounds_component.h"
#include "ga/graph/components/tint_component.h"

class RectNode : public ga::Node
{
public:
	void setup() override
	{
		component<ga::Bounds>()     = ga::Bounds( { 0, 0 }, { 50, 50 } );
		component<ga::Tint>().color = ga::Color( 0.5f, 0.5f, 0.5f, 1.f );
	}

	void draw() override
	{
		// using openFrameworks native draw calls for simplicity
		ofPushStyle();
		ofSetColor( ga::toOf( component<ga::Tint>().color ) );
		auto& bounds = component<ga::Bounds>();
		ofDrawRectangle( bounds.min, bounds.size().x, bounds.size().y );
		ofPopStyle();
	}
};
