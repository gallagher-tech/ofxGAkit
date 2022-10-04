#pragma once
#pragma once

#include "ofxGANative.h"
#include "of3dPrimitives.h"

class SphereNode : public ga::Node
{
	friend ga::Node;

public:
	SphereNode();
	~SphereNode();

protected:
	void setup() override;
	void draw() override;

private:
	ofSpherePrimitive m_sphere;
	float m_sphereSize = 250;
};
