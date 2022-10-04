#include "ButtonNode.h"
#include "ofGraphics.h"
#include "ga/graph/components/bounds_component.h"
ButtonNode::ButtonNode()
{
}
ButtonNode::~ButtonNode()
{
	disconnectTouch();
}

void ButtonNode::setup()
{
	buttonDownColor = ga::Color( 1, 0, 0, 1 );
	buttonUpColor   = ga::Color( 1, 1, 0, 1 );

	// add bound to help determine interactive area
	auto bounds = std::shared_ptr<ga::Bounds>( new ga::Bounds( ga::vec2( 0, 0 ), m_size) );
	addComponent<ga::Bounds>( bounds );

	createComponent<ga::TouchZone>();
	component<ga::TouchZone>().onTouchEvent.connect( [this]( ga::TouchZone::Event& evt ) { handleTouchEvent( evt ); } );
}

void ButtonNode::update()
{
}

void ButtonNode::draw()
{
	ofPushStyle();
	ofSetColor( ga::toOf(m_drawColor) );
	ofDrawRectangle( ga::vec2( 0.0f, 0.0f ), m_size.x, m_size.y );
	std::string text = "draw order " + ofToString( m_drawOrder );
	ofDrawBitmapString( text, ga::vec2( 0.0f, -10.0f ));
	ofPopStyle();
}

void ButtonNode::onDrawIndexChange()
{
	m_drawOrder =  getSceneDrawIndex();
	// update touch event when draw order is changed
	component<ga::TouchZone>().disconnectTouch();

	// btns can be assinged with group id to establish manual order
	// the higher the index number, the later signal hits
	// do not rely on the signal lib to establish order by added order, it is not a guarantee
	component<ga::TouchZone>().connectTouch( getScene(), 0 - m_drawOrder );
}

void ButtonNode::handleTouchEvent( ga::TouchZone::Event& touchEvt )
{
	ga::vec3 localPos = scenePosToLocal(touchEvt.scenePosition );
	switch ( touchEvt.type ) {
		case ga::TouchZone::Event::Type::PRESS:
			m_touchDownPos = localPos;
			m_drawColor    = buttonDownColor;
			break;
		case ga::TouchZone::Event::Type::DRAG_OFF:
			setTranslation( touchEvt.scenePosition - m_touchDownPos );
			break;
		case ga::TouchZone::Event::Type::DRAG_INSIDE:
			setTranslation( touchEvt.scenePosition - m_touchDownPos );
			break;
		case ga::TouchZone::Event::Type::RELEASE:
			m_drawColor = buttonUpColor;
			m_buttonReleaseSignal( ga::vec2( touchEvt.scenePosition.x, touchEvt.scenePosition.y ), buttonDownColor );
			break;
		default:
			break;
	}
}
