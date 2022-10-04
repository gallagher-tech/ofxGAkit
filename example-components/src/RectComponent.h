#pragma once

#include "ga/graph/component.h"
#include "ofGraphics.h"
#include "ofLog.h"
class RectShapeComponent : public ga::Component
{
public:
	glm::vec2 getSize() { return m_size; }
	void setSize( glm::vec2 size )
	{
		m_size = size;
	}

	void setAlpha( float alpha )
	{
		m_drawColor.a = alpha;
	}
	void setDrawColor( ga::Color color )
	{
		m_drawColor = color;
	}

	void draw()
	{
		ofPushStyle();
		ofSetColor( ga::toOf( m_drawColor ) );
		ofDrawRectangle( glm::vec2( 0 ), m_size.x, m_size.y );

		ofPopStyle();
	};

private:
	glm::vec2 m_size    = glm::vec2( 100, 100 );
	ga::Color m_drawColor = ga::Color();
};