#pragma once

#include "ofMain.h"
#include "ofxGANative.h"
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

	std::shared_ptr<ga::Scene> scene;
	std::shared_ptr<ga::Node> rectParent;

	ga::Color indicatorColor { 1., 0., 0., 1. };
	ofRectangle indicatorRect;

	// animates the rects from the one fixed pos to another
	void animateRects( float startY, float endY, ga::EasingFn easeFn );

	// animates the animation indicator
	void animateIndicator( ga::EasingFn easeFn );
};
