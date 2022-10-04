#pragma once
#include "ga/graph/node.h"
#include "ofGraphics.h"
#include "ga/graph/components/paragraph_component.h"

class MyNode : public ga::Node
{
	// important  
	friend ga::Node;

public:
	MyNode();
	~MyNode();

protected:
	void setup() override;
	void update() override;
	void draw() override;

	// keeps track of paragraph component
	std::shared_ptr<ga::Paragraph> m_paragraphComponent;
};

