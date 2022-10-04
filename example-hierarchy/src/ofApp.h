#pragma once

#include "ofMain.h"
#include "ofxGAKit.h"

#include "SphereNode.h"
#include "SquareNode.h"

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
	std::vector<std::shared_ptr<ga::Node>> m_nodes;  // keep track of nodes

	std::shared_ptr<SphereNode> m_sphereNode;

	ofSpherePrimitive m_sphere;
	ofCamera m_cam;

	int m_active_node = 0;
};
