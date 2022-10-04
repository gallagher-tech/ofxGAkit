#pragma once
#include "ga/signal.h"
#include "ga/graph/node.h"
#include "ga/graph/scene.h"
#include "ga/events.h"
#include "ga/color.h"
#include "ga/graph/components/touchzone_component.h"
#include "ofLog.h"

class ButtonNode : public ga::Node
{
	friend ga::Node;

public:
	ButtonNode();
	~ButtonNode();

	ga::Signal<ga::vec2&, ga::Color&>& getButtonReleaseSignal() { return m_buttonReleaseSignal; }
	void setDownColor( ga::Color c ) { buttonDownColor = c; }
	void setUpColor( ga::Color c )
	{
		buttonUpColor = c;
		m_drawColor   = buttonUpColor;
	}
	ga::vec2& getSize() { return m_size; }

protected:
	void setup() override;
	void update() override;
	void draw() override;
	void onDrawIndexChange() override;

	void handleTouchEvent( ga::TouchZone::Event& touchEvt );

	void disconnectTouch()
	{
		// always disconnect signals, or make them scoped
		m_buttonReleaseSignal.disconnect_all();
		component<ga::TouchZone>().onTouchEvent.disconnect_all();
	}

private:
	// signals
	ga::Signal<ga::vec2&, ga::Color&> m_buttonReleaseSignal;

	// layout
	ga::Color buttonDownColor;
	ga::Color buttonUpColor;

	// mouse/touch pos
	glm::vec3 m_touchDownPos;
	bool m_isActive = false;

	// should we capture event and prevent propagation?
	bool m_isCapturingTouch = true;

	// size
	glm::vec2 m_size    = glm::vec2( 100, 100 );
	float m_alpha       = 1.0f;
	ga::Color m_drawColor = ga::Color( 1, 1, 1, 1 );

	// store draw order
	int m_drawOrder = 0;
};
