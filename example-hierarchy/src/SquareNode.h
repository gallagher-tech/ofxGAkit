#pragma once
#include "ofxGAKit.h"

class SquareNode : public ga::Node
{
	friend ga::Node;

public:
	SquareNode();
	~SquareNode();
	void setColor( ofColor color ) { m_color = color; }
	void setIndex( int index ) { m_index = index; }

protected:
private:
	void setup() override;
	void draw() override;

	ofColor m_color;
	int m_index = 0;
};
