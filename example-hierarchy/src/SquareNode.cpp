#include "SquareNode.h"
#include "ofGraphics.h"
SquareNode::SquareNode()
{
}

SquareNode::~SquareNode()
{
}

void SquareNode::setup()
{
}

void SquareNode::draw()
{
	float rectSize = 75;
	glm::vec2 size = glm::vec2( rectSize + rectSize * m_index, rectSize + rectSize * m_index );

	// always push and pop
	// or it will affects other stuff drawing in the app
	ofPushMatrix();
	ofTranslate( size.x * -0.5f, size.y * -0.5f );  // draw centered
	ofSetColor( m_color );
	ofDrawRectangle( 0, 0, size.x, size.y );

	ofSetColor( 255 );
	ofDrawBitmapString( getName(), glm::vec2( 0 ) );
	ofPopMatrix();
}
