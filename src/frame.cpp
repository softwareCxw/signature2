#include "frame.h"

void frame::setup()
{
	i_choose = CHOOSE;
	_fbo.allocate(1920, 1080);

	_chooseBack.setup();
	_signature.setup();
}

void frame::update()
{
	switch(i_choose)
	{
	case CHOOSE :
		_chooseBack.update();
		break;
	case SIGNATURE :
		_signature.update();
		break;
	default:
		break;
	}
}

void frame::draw()
{
	_fbo.begin();
	ofClear(0);
	switch(i_choose)
	{
	case CHOOSE :
		_chooseBack.draw();
		break;
	case SIGNATURE :
		_signature.draw();
		break;
	default:
		break;
	}
	_fbo.end();
	_fbo.draw(0, 0, ofGetWidth(), ofGetHeight());
}

void frame::mouseMoved( int x, int y )
{

}

void frame::mouseDragged( int x, int y, int button )
{
	x = _fbo.getWidth() / ofGetWidth() * x;
	y = _fbo.getHeight() / ofGetHeight() *y;

	switch(i_choose)
	{
	case CHOOSE :
		_chooseBack.mouseTrigger(MOUSE_DRAGGED, x, y, button);
		break;
	case SIGNATURE :
		_signature.mouseTrigger(MOUSE_DRAGGED, x, y, button);
		break;
	default:
		break;
	}
}

void frame::mousePressed( int x, int y, int button )
{
	x = _fbo.getWidth() / ofGetWidth() * x;
	y = _fbo.getHeight() / ofGetHeight() *y;
	switch(i_choose)
	{
	case CHOOSE :
		_chooseBack.mouseTrigger(MOUSE_PRESSED, x, y, button);
		
		break;
	case SIGNATURE :
		_signature.mouseTrigger(MOUSE_PRESSED, x, y, button);
		break;
	default:
		break;
	}
}

void frame::mouseReleased( int x, int y, int button )
{
	x = _fbo.getWidth() / ofGetWidth() * x;
	y = _fbo.getHeight() / ofGetHeight() *y;

	switch(i_choose)
	{
	case CHOOSE :
		_chooseBack.mouseTrigger(MOUSE_RELEASED, x, y, button);
		if(_chooseBack.is_next()) {
			i_choose = SIGNATURE;
			_signature.setSignatureImg(_chooseBack.getSignatureImg());
			_chooseBack.revect();
		}
		break;
	case SIGNATURE :
		_signature.mouseTrigger(MOUSE_RELEASED, x, y, button);
		if(_signature.is_next()) {
			i_choose = CHOOSE;
			_signature.revect();
		}
		break;
	default:
		break;
	}
}

