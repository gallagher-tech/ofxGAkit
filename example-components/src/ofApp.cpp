// image credit:
// (CC BY 2.0) Attribution Some rights reserved by [fazen](https://flickr.com/photos/fazen/)

#include "ofApp.h"
#include "RectComponent.h"
#include "ga/graph/components/paragraph_component.h"
//--------------------------------------------------------------
void ofApp::setup(){
	m_scene = ga::Scene::create();
	m_scene->setName( "scene" );

	for ( size_t i = 0; i < 15; i++ ) {
		for ( size_t j = 0; j < 15; j++ ) {
			// add a ga::Node
			auto node = m_scene->addNode<ga::Node>();
			// add a custom component
			node->createComponent<RectShapeComponent>();
			// similar to getComponent(), 
			// however getComponent() will return nullptr if not found
			node->component<RectShapeComponent>().setDrawColor( ga::Color( 0.3f, 0.3f, 0.3f, 1.0f ) );

			// doing some visual stuff
			node->setScale( ga::vec3( 0.5f, 2, 0 ) );
			node->setTranslation( ga::vec2( i * 100, j * 100 ) );

			// quick access to the node's update fn
			node->setUpdateFn( [node]() {
				node->setEulerRotation( ga::vec3( 0, 0, ofGetElapsedTimef() ) );
			} );
		}
	}

	// add a ga::Node to hold paragraph component
	auto textNode = m_scene->addNode<ga::Node>();

	// define font
	ofTrueTypeFontSettings settings( "RobotoSerif-Black.ttf", 72 );

	// optional parameters
	settings.antialiased = true;
	settings.contours    = false;
	settings.simplifyAmt = 0.3f;
	settings.dpi         = 72;

	// load font and give it a name
	// note: try loading resources like fonts and images at startup. 
	//       once cached, load them at any point when needed.   
	ga::fontCache().load( "font-black", settings );

	// write some text
	auto labelComp = textNode->createComponent<ga::Paragraph>();
	labelComp->setFont( ga::fontCache().get( "font-black" ) );
	labelComp->setText( "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua." );
	labelComp->setSize( ga::vec2( ofGetWindowWidth(), ofGetWindowHeight() ) );
	labelComp->setTextColor( ga::Color( 0.5f, 0.5f, 0.5f, 1 ) );

	// add a custom node containing multiple components
	m_node = m_scene->addNode<MyNode>();
}

//--------------------------------------------------------------
void ofApp::update(){
	m_scene->update();
	auto x = sin( ofGetElapsedTimef() ) * ofGetWindowWidth() * 0.5f + ofGetWindowWidth() * 0.5f;
	auto y = ofGetWindowHeight() * 0.7f;

	m_node->setTranslation( ga::vec2(x, y) );
}

//--------------------------------------------------------------
void ofApp::draw(){
	m_scene->draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
