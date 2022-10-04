#include "ofApp.h"
#include "RectNode.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	m_scene = ga::Scene::create();
	m_scene->setName( "scene" );

	// create button and add to scene
	m_button = m_scene->addNode<ButtonNode>();

	// set button pos to center of window
	m_button->setTranslation( ga::vec2( ofGetWindowSize() * 0.5f ) - m_button->getSize() * 0.5f );

	// connect button's function to scene's touch/mouse events
	// trigger lamda when signal is emitted
	m_button->getButtonReleaseSignal().connect( [this]( ga::vec2& pos, ga::Color& color) { ofLogNotice() << "lamda when button released"; } );

	// bind to a member function when signal is emitted
	m_button->getButtonReleaseSignal().connect( &ofApp::onButtonReleased, this );

	auto btn = m_scene->addNode<ButtonNode>();
	btn->setTranslation( ga::vec2( ofGetWindowSize() * 0.2f ) - m_button->getSize() * 0.5f );
	btn->setDownColor( ga::Color( 0, 0, 1, 1 ) );
	btn->setUpColor( ga::Color( 0, 1, 1, 1 ) );
	btn->getButtonReleaseSignal().connect( &ofApp::onButtonReleased, this );

	auto btn2 = m_scene->addNode<ButtonNode>();
	btn2->setTranslation( ga::vec2( ofGetWindowSize() * 0.3f ) - m_button->getSize() * 0.5f );
	btn2->setDownColor( ga::Color( 0, 0, 0.4f, 1.0f ) );
	btn2->setUpColor( ga::Color( 0, 0.4f, 0.4f, 1.0f ) );
	btn2->getButtonReleaseSignal().connect( &ofApp::onButtonReleased, this );


	// draw some nodes with the same rect shape component
	for ( size_t i = 0; i < 10; i++ ) {
		auto node = m_scene->addNode<RectNode>();
		node->setTranslation( ga::vec2( 100 * i + 40, 30 ) );
		m_nodes.push_back( node );
	}

	auto printNode = []( std::shared_ptr<ga::Node> node ) {
		ofLogNotice() << "Node [" << node->getSceneDrawIndex() << "]: " << node->getName();
	};
	m_scene->forEachNode( printNode );
}

//--------------------------------------------------------------
void ofApp::update()
{
	m_scene->update();
}

//--------------------------------------------------------------
void ofApp::draw()
{
	m_scene->draw();

	// draw some event indicators
	ofDrawBitmapString( "mouse/touch pressed", ga::vec2( 50, 580 ) );
	ofDrawBitmapString( "mouse/touch dragged", ga::vec2( 400, 580 ) );
	ofDrawBitmapString( "mouse/touch released", ga::vec2( 750, 580 ) );

	ofSetColor( 50 );
	ofDrawRectangle( ga::vec2( 50, 600 ), 200, 10 );
	ofDrawRectangle( ga::vec2( 400, 600 ), 200, 10 );
	ofDrawRectangle( ga::vec2( 750, 600 ), 200, 10 );

	ofSetColor( 255 );
	if ( m_isDown )
		ofDrawRectangle( ga::vec2( 50, 600 ), 200, 10 );
	if ( m_isDragging )
		ofDrawRectangle( ga::vec2( 400, 600 ), 200, 10 );
	if ( m_isUp )
		ofDrawRectangle( ga::vec2( 750, 600 ), 200, 10 );
}

//--------------------------------------------------------------
void ofApp::keyPressed( int key )
{
}

//--------------------------------------------------------------
void ofApp::keyReleased( int key )
{
}

//--------------------------------------------------------------
void ofApp::mouseMoved( int x, int y )
{
	if ( m_isUp ) m_isUp = false;
}

//--------------------------------------------------------------
void ofApp::mouseDragged( int x, int y, int button )
{
	// connect oF touch event to scene touch event
	ga::TouchEvent evt;
	evt.position = ga::vec2 { x, y };
	evt.type     = ga::TouchEvent::Type::DRAG;
	m_scene->onTouchEvent( evt );

	m_isDown     = false;
	m_isDragging = true;
	m_isUp       = false;
}

//--------------------------------------------------------------
void ofApp::mousePressed( int x, int y, int button )
{
	// connect oF touch event to scene touch event
	ga::TouchEvent evt;
	evt.position = ga::vec2 { x, y };
	evt.type     = ga::TouchEvent::Type::PRESS;
	m_scene->onTouchEvent( evt );

	m_isDown     = true;
	m_isDragging = false;
	m_isUp       = false;
}

//--------------------------------------------------------------
void ofApp::mouseReleased( int x, int y, int button )
{
	// connect oF touch event to scene touch event
	ga::TouchEvent evt;
	evt.position = ga::vec2 { x, y };
	evt.type     = ga::TouchEvent::Type::RELEASE;
	m_scene->onTouchEvent( evt );

	m_isDown     = false;
	m_isDragging = false;
	m_isUp       = true;
}
//--------------------------------------------------------------
void ofApp::onButtonReleased( ga::vec2 touchPos, ga::Color color )
{
	// this function is getting called when button gets released
	ofLogNotice() << "button released! changing bg color!";
	auto bgColor = ga::toOf( color );
	ofBackground( bgColor );

	// different from ofColor, ga::Color is normalized
	auto c = ga::Color( ofRandom( 1.0f ), ofRandom( 1.0f ), ofRandom( 1.0f ), 1 );
	for ( size_t i = 0; i < m_nodes.size(); i++ ) {
		// set animation starting value
		// clear timeline
		auto n                         = m_nodes[i];
		n->component<ga::Tint>().color = ga::Color( c.r, c.g, c.b, 1.0f );
		n->component<ga::Timeline>().clear();

		// start timeline animation, animate alpha value
		n->component<ga::Timeline>().add( 255.0f, 0.0f, ga::ease::material, [n, i, c]( const float& v ) {
			                            n->component<ga::Tint>().color = ga::Color( c.r, c.g, c.b, v );
		                            } )
		    ->startAfterDelay( 50 * i, 1000 );
	}
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
