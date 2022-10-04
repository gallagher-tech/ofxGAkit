#pragma once

#include "ofxGANative.h"
class Derived : public ga::Node
{

protected:
	// these 3 methods are inherited from ga::Node
	// we override them to customize the Derived node's behavior

	void setup() override;   // called once on node creation
	void update() override;  // called each scene update
	void draw() override;    // called each scene draw

	// since we declared these methods `protected`,
	// we need to add ga::Node class as a `friend`
	// so it can call these methods internally

	friend class ga::Node;  // or we could just make these methods `public`

public:
	void setRotationSpeed( float degPerSec ) { m_rotationSpeed = degPerSec; }

private:
	float m_rotationSpeed = 1.f;
};
