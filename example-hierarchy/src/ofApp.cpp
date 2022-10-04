#include "ofApp.h"
static const int NUM_LAYERS = 5;

//--------------------------------------------------------------
void ofApp::setup()
{
	m_scene = ga::Scene::create();

	// we are drawing everything from back to front
	// the index label of node is starting from 0
	int index = 0;

	// add sphere node in the back
	// add name to node to track them easier
	m_sphereNode = ga::Node::create<SphereNode>();
	m_scene->addNode( m_sphereNode );
	m_sphereNode->setName( "node-" + to_string( index ) );
	m_sphereNode->setTranslation( ga::vec3( ofGetWindowSize() * 0.5f, 0 ) );

	// store node for tracking
	m_nodes.push_back( m_sphereNode );

	std::shared_ptr<ga::Node> previous_node = m_sphereNode;

	// draw from back to front
	for ( int i = NUM_LAYERS - 1; i >= 0; i-- ) {

		index++;

		// create nodes here
		auto node = ga::Node::create<SquareNode>();
		node->setName( "node-" + ofToString( index ) );

		// store node for tracking
		m_nodes.push_back( node );

		// create the hierarchy
		previous_node->addChild( node );

		const float color_step = 20.0f;
		auto drawColor         = ofColor( i * color_step );

		node->setColor( drawColor );
		node->setIndex( i );

		previous_node = node;
	}
}

//--------------------------------------------------------------
void ofApp::update()
{
	m_scene->update();

	ofSetWindowTitle( "fps:" + ofToString( ofGetFrameRate(), 2 ) );

	glm::vec3 rot( 0.0f, 0.0f, 0.005f );
	m_nodes[m_active_node]->setEulerRotation( m_nodes[m_active_node]->getEulerRotation() + rot );
}

//--------------------------------------------------------------
void ofApp::draw()
{
	m_scene->draw();

	// draw instructions
	ofDrawBitmapString( "Press left/right key to switch layers", glm::vec2( 100, 100 ) );
	ofDrawBitmapString( "Active node index: " + ofToString( m_active_node ), glm::vec2( 100, 120 ) );
}

//--------------------------------------------------------------
void ofApp::keyPressed( int key )
{
	if ( key == OF_KEY_LEFT ) {
		m_active_node--;
	}

	if ( key == OF_KEY_RIGHT ) {
		m_active_node++;
	}

	if ( m_active_node < 0 ) {
		m_active_node = 0;
	}

	if ( m_active_node > NUM_LAYERS ) {
		m_active_node = NUM_LAYERS;
	}

	ofLogNotice() << "active node index: " << m_active_node;
}

//--------------------------------------------------------------
void ofApp::keyReleased( int key )
{
}

//--------------------------------------------------------------
void ofApp::mouseMoved( int x, int y )
{
}

//--------------------------------------------------------------
void ofApp::mouseDragged( int x, int y, int button )
{
}

//--------------------------------------------------------------
void ofApp::mousePressed( int x, int y, int button )
{
}

//--------------------------------------------------------------
void ofApp::mouseReleased( int x, int y, int button )
{
}

//--------------------------------------------------------------
void ofApp::mouseEntered( int x, int y )
{
}

//--------------------------------------------------------------
void ofApp::mouseExited( int x, int y )
{
}

//--------------------------------------------------------------
void ofApp::windowResized( int w, int h )
{
}

//--------------------------------------------------------------
void ofApp::gotMessage( ofMessage msg )
{
}

//--------------------------------------------------------------
void ofApp::dragEvent( ofDragInfo dragInfo )
{
}
