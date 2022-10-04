#pragma once

#include "ofMain.h"
#include "ofxGANative.h"
#include "ButtonNode.h"
#include "RectNode.h"

class ofApp : public ofBaseApp
{

public:
	void setup();
	void update();
	void draw();

	void keyPressed( int key );
	void keyReleased( int key );
	void mouseMoved( int x, int y );
	void mouseDragged( int x, int y, int button );
	void mousePressed( int x, int y, int button );
	void mouseReleased( int x, int y, int button );
	void mouseEntered( int x, int y );
	void mouseExited( int x, int y );
	void windowResized( int w, int h );
	void dragEvent( ofDragInfo dragInfo );
	void gotMessage( ofMessage msg );

private:
	std::shared_ptr<ga::Scene> m_scene;

	// connetion handling
	void onButtonReleased( ga::vec2 touchPos, ga::Color color );

	// button
	std::shared_ptr<ButtonNode> m_button;

	// shapes
	std::vector<std::shared_ptr<RectNode>> m_nodes;

	// indicator variables
	float m_unitWidth  = ofGetWidth() / 7.0f;
	float m_unitHeight = 5;
	float m_indicatorY = 150;

	bool m_isDown     = false;
	bool m_isDragging = false;
	bool m_isUp       = false;
};
