#include "ofApp.h"
#include "Derived.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	scene = ga::Scene::create<ga::Scene>();
	scene->setName( "my_scene" );

	// create 20 by 20 grid of nodes
	for ( int i = 0; i < 20; i++ ) {
		for ( int j = 0; j < 20; j++ ) {

			// create a derived node class
			auto node = ga::Node::create<Derived>();
			// name the nodes with unique names so they get called easily by name
			node->setName( "Nodey McNoder x" + ofToString( i ) + " y" + ofToString( j ) );

			// set node position in 3d space
			node->translate( ga::vec3( i * 60, j * 60, 0 ) );

			// rotation speed is special attribute of Derived node
			node->setRotationSpeed( 1.f + i + j );  // # degrees rotation per second

			// add node to scene
			scene->addNode( node );

			// adding a child node to draw something else
			auto child = node->addChild( ga::Node::create<ga::Node>() );

			// this is a convenient way to change a node's update function
			// on the fly, without creating a subclass
			child->setUpdateFn( [child]() {
				child->rotateAround( { 0, 0, 1 }, ofGetLastFrameTime() );
			} );

			// we can change the node's draw function in the same way
			child->setDrawFn( []() {
				// always push and pop
				// or it will affects other stuff drawing in the app
				ofPushMatrix();
				ofPushStyle();

				ofSetColor( 0 );
				ofDrawLine( 0, 0, 100, 100 );

				ofPopStyle();
				ofPopMatrix();
			} );
		}
	}

	// another way to add node, set name separately
	auto node = ga::Node::create();
	node->setName( "some other node" );

	// add to scene
	scene->addNode( node );

	// draw stuff quickly by using lambda functions
	node->setDrawFn( []() {
		// always push and pop
		// or it will affects other stuff drawing in the app
		ofPushMatrix();
		ofPushStyle();

		ofSetColor( 255 );
		ofDrawBitmapString( "Welcome to GA-Graph!", 50, 50 );

		ofPopStyle();
		ofPopMatrix();
	} );

	// every node has an unique uid
	ofLogNotice() << node->getUuid();

	// get name of the node
	ofLogNotice() << "name is: " << node->getName();
}

//--------------------------------------------------------------
void ofApp::update()
{
	scene->update();

	ofSetWindowTitle( ofToString( ofGetFrameRate(), 1 ) );
}

//--------------------------------------------------------------
void ofApp::draw()
{
	scene->draw();
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
