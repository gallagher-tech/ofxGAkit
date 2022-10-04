#include "SphereNode.h"
#include "ofGraphics.h"
SphereNode::SphereNode()
{
}

SphereNode::~SphereNode()
{
}

void SphereNode::setup()
{
	m_sphere.set( m_sphereSize, 5 );
}

void SphereNode::draw()
{

	// always push and pop
	// or it will affects other stuff drawing in the app
	ofPushMatrix();
	ofSetColor( 255 );
	m_sphere.rotateDeg( ofGetElapsedTimef() * 0.01f, glm::vec3( 1, 0, 0 ) );
	m_sphere.drawWireframe();
	ofPopMatrix();

	ofPushMatrix();
	ofSetColor( 255 );
	ofDrawBitmapString( getName(), glm::vec2( -m_sphereSize ) );
	ofPopMatrix();
}
