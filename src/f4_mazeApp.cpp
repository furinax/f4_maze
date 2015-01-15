#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "MazeGenerator.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class f4_mazeApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();

	MazeGenerator mg;
};

void f4_mazeApp::setup()
{
	setWindowSize(1280, 720);
	mg.setup();

}

void f4_mazeApp::mouseDown( MouseEvent event )
{

}

void f4_mazeApp::update()
{
	mg.update();
}

void f4_mazeApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
	mg.draw();
}

CINDER_APP_NATIVE( f4_mazeApp, RendererGl )
