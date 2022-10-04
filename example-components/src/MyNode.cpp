#include "MyNode.h"
#include "ga/graph/components/image_component.h"
#include "ga/graph/components/tint_component.h"

MyNode::MyNode()
{
}

MyNode::~MyNode()
{
}

void MyNode::setup()
{
	
	// load a texture "cat.jpg" into cache and name it "img"
	ga::textureCache().load( "img", "cat.jpg");
	ga::Rect bounds2D   = { 50, 50, 250, 150 }; // give it bounds
	ga::FitMode fitMode = ga::FitMode::NONE; // fit within bounds

	// load resources by name
	// use std::make_shared or std::shared_ptr for custom constructors
	// auto imgComp = std::make_shared<ga::Image>( "img", bounds2D, fitMode );  // valid
	auto imgComp = std::shared_ptr<ga::Image>( new ga::Image( "img", bounds2D, fitMode ) );  // valid
	addComponent<ga::Image>( imgComp );
	
	// one node should only have one type of component
	// you can call the componet like this 
	// it will create a component if the component does not exist
	component<ga::Image>().crop = true; // crop if fitMode is NONE

	// define font 
	ofTrueTypeFontSettings settings( "RobotoSerif-Regular.ttf", 24 );

	// optional parameters
	settings.antialiased = true;
	settings.contours    = false;
	settings.simplifyAmt = 0.3f;
	settings.dpi         = 72;

	// load font and give it a name, this can happen at startup to have font ready
	ga::fontCache().load( "font", settings );

	// write some text
	m_paragraphComponent = createComponent<ga::Paragraph>();
	m_paragraphComponent->setFont( ga::fontCache().get( "font" ) );
	m_paragraphComponent->setText( "hello world" );
	m_paragraphComponent->setSize( ga::vec2( 1200, 1200 ) );
	m_paragraphComponent->setTextColor( ga::Color( 1,1,1,1 ) );

	// a custome function to draw component with offset
	// if not defined the component will be drawn at the anchor of the node
	m_paragraphComponent->setTextOffset( glm::vec2( 50, 0 ) );

	// draw to a fbo if needed
	//m_paragraphComponent->setFboCacheEnabled( true );

	// add tint to everything
	// only works with components that does not have a push/pop or ignoring scoped color 
	createComponent<ga::Tint>();

	// component<ga::Tint>() = ga::Tint();
	component<ga::Tint>().color = ga::Color( 0.5, 0.5, 0.5, 0.5 );


}

void MyNode::update()
{
}

void MyNode::draw()
{
	// if a component had a update() or draw() fn
	// it will get called automatically
	// draw non component stuff
	ofPushMatrix();
	ofSetColor( ofColor( 255 ) );
	ofDrawCircle( ga::vec2( 0, 10 * cos(ofGetElapsedTimef() * 10 )), 10 );
	ofPopMatrix();
}
