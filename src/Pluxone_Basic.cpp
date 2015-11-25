#include "Pluxone_Basic.h"


Pluxone_Basic::Pluxone_Basic(void)
{
}


Pluxone_Basic::~Pluxone_Basic(void)
{
}

void Pluxone_Basic::mouseTrigger(int _type,int x,int y,int button)
{
	switch(_type)
	{
	case MOUSE_MOVED:mouseMoved(x,y,button);break;
	case MOUSE_DRAGGED:mouseDragged(x,y,button);break;
	case MOUSE_PRESSED:mousePressed(x,y,button);break;
	case MOUSE_RELEASED:mouseReleased(x,y,button);break;
	default:break;
	}
}

void Pluxone_Basic::keyTrigger(int _type,int key)
{
	switch(_type)
	{
	case KEY_PRESSED:keyPressed(key);break;
	case KEY_RELEASED:keyReleased(key);break;

	default:break;
	}
}