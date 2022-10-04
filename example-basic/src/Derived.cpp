#include "Derived.h"
#include "ofGraphics.h"
#include "ofEvents.h"
void Derived::setup()
{
	// this is called automatically when the node is created
	std::cout << "I made a Derived" << '\n';
}

void Derived::update()
{
	// this changes nodes' rotation over time
	// rotate around z-axis by X degrees per second
	rotateAround( glm::vec3( 0, 0, 1 ), glm::radians( m_rotationSpeed ) * ofGetLastFrameTime() );
}

void Derived::draw()
{
	// always push and pop
	// or it will affect other stuff drawing in the app
	ofPushMatrix();
	ofPushStyle();

	// draw bordered square with corner at origin
	ofSetColor( 0 );
	ofDrawRectangle( 0, 0, 50, 50 );  // black rectangle for border

	ofSetColor( 150 );
	ofDrawRectangle( 2, 2, 46, 46 );  // grey inset rectangle

	// draw bordered circle centered at origin
	ofSetColor( 0 );
	ofDrawCircle( 0, 0, 5 );

	ofSetColor( 150 );
	ofDrawCircle( 0, 0, 3 );  // circle on origin

	ofPopStyle();
	ofPopMatrix();
}