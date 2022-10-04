#include "ofApp.h"

namespace config {

const int numRect       = 17;
const float rectStartY  = 240;
const float rectEndY    = 600;
const float rectPadding = 10;
const long animDurMs    = 950;
const long animDelayMs  = 50;

const glm::vec2 textPos    = { 50, 100 };
const float textLineHeight = 20;

const glm::vec2 indicatorPos     = { 50, 85 };
const glm::vec2 indicatorMaxSize = { 1000, 20 };

}  // namespace config

//--------------------------------------------------------------
void ofApp::setup()
{
	ofBackground( 50 );

	// create the scene
	scene = ga::Scene::create();

	// add a parent node to contain a set of RectNodes
	rectParent = scene->addNode();

	// create a set of RectNodes that draw rectangles
	for ( size_t i = 0; i < config::numRect; i++ ) {
		auto rectNode = rectParent->addChild<RectNode>();

		// get RectNode's built-in Bounds component
		auto& rectBounds = rectNode->component<ga::Bounds>();

		// distribute RectNodes in a horizontal row
		rectNode->setTranslation(
		    ga::vec2 {
		        config::rectPadding + i * ( rectBounds.size().x + config::rectPadding ),
		        config::rectStartY } );
	}

	// we'll draw an "indicator" manually to highlight the current animation style
	indicatorRect = ofRectangle( config::indicatorPos, 0, config::indicatorMaxSize.y );  // indicator will animate from 0 width to max width
}

//--------------------------------------------------------------
void ofApp::update()
{
	// update scene every frame
	scene->update();
}

//--------------------------------------------------------------
void ofApp::draw()
{
	// draw scene every frame
	// this will draw the RectNodes
	scene->draw();

	// draw the indicator manually
	ofPushStyle();
	ofSetColor( ga::toOf( indicatorColor ) );
	ofDrawRectangle( indicatorRect );
	ofPopStyle();

	// draw text instructions

	ofDrawBitmapString( "Press number key to start animation", config::textPos - glm::vec2( 0, 30 ) );

	ofDrawBitmapString( "1: cubeInQuadOut", config::textPos );
	ofDrawBitmapString( "2: expoIn", config::textPos + glm::vec2( 0, config::textLineHeight ) );
	ofDrawBitmapString( "3: expoInOut", config::textPos + glm::vec2( 0, config::textLineHeight * 2 ) );
	ofDrawBitmapString( "4: expoOut", config::textPos + glm::vec2( 0, config::textLineHeight * 3 ) );
	ofDrawBitmapString( "5: material", config::textPos + glm::vec2( 0, config::textLineHeight * 4 ) );
	ofDrawBitmapString( "6: materialEnter", config::textPos + glm::vec2( 0, config::textLineHeight * 5 ) );
	ofDrawBitmapString( "7: materialExit", config::textPos + glm::vec2( 0, config::textLineHeight * 6 ) );
}

//--------------------------------------------------------------
void ofApp::animateRects( float startY, float endY, ga::EasingFn easeFn )
{
	// loop through the RectNodes
	for ( int i = 0; i < rectParent->getChildren().size(); i++ ) {

		// get the i'th RectNode
		auto c = rectParent->getChildren()[i];

		// clear any in-progress / pending animations from this node's timeline
		c->component<ga::Timeline>().clear();

		// create an animation on the RectNode's timeline:
		// from start value to end value, using given easing function
		// the lambda is called with the current value every update()
		c->component<ga::Timeline>()
		    .add( startY, endY, easeFn,
		          [c, i]( const float& y ) {
			          c->setTranslation( ga::vec2( c->getTranslation().x, y ) );
		          } )
		    ->startAfterDelay( config::animDelayMs * i, config::animDurMs );  // delay animation by index
	}
}

//--------------------------------------------------------------

void ofApp::animateIndicator( ga::EasingFn easeFn )
{
	// the indicator is drawn manually, so we'll just attach the animation
	// to the scene's root node
	auto root = scene->getRootNode();

	// clear previous animations
	root->component<ga::Timeline>().clear();

	root->component<ga::Timeline>()
	    .add(
	        0.f, 1.f, easeFn,  // we'll animate from 0 to 1

	        // callback called on every animation "tick"
	        [this]( const float& value ) {
		        indicatorRect.width = config::indicatorMaxSize.x * value;  // grow
		        indicatorColor.a    = 1. - value;                          // fade out
	        },

	        // extra callback to be executed when animation is finished
	        [this, easeFn]() {
		        ofLogNotice() << "indicator animation ended, restore rect location";
		        animateRects( config::rectEndY, config::rectStartY, easeFn );
	        } )
	    ->startNow( config::animDurMs + config::animDelayMs * config::numRect );
}

//--------------------------------------------------------------
void ofApp::keyPressed( int key )
{
	ga::EasingFn easeFn;
	switch ( key ) {
		case '1': {
			easeFn          = ga::ease::cubeInQuadOut;
			indicatorRect.y = config::indicatorPos.y;
			break;
		}
		case '2': {
			easeFn          = ga::ease::expoIn;
			indicatorRect.y = config::indicatorPos.y + config::textLineHeight;
			break;
		}
		case '3': {
			easeFn          = ga::ease::expoInOut;
			indicatorRect.y = config::indicatorPos.y + config::textLineHeight * 2;
			break;
		}
		case '4': {
			easeFn          = ga::ease::expoOut;
			indicatorRect.y = config::indicatorPos.y + config::textLineHeight * 3;
			break;
		}
		case '5': {
			easeFn          = ga::ease::material;
			indicatorRect.y = config::indicatorPos.y + config::textLineHeight * 4;
			break;
		}
		case '6': {
			easeFn          = ga::ease::materialEnter;
			indicatorRect.y = config::indicatorPos.y + config::textLineHeight * 5;
			break;
		}
		case '7': {
			easeFn          = ga::ease::materialExit;
			indicatorRect.y = config::indicatorPos.y + config::textLineHeight * 6;
			break;
		}
	}

	if ( easeFn ) {
		animateRects( config::rectStartY, config::rectEndY, easeFn );
		animateIndicator( easeFn );
	}
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
