#pragma once
#include "PluxOne_include.h"

class Pluxone_Basic
{
public:
	Pluxone_Basic(void);
	~Pluxone_Basic(void);

	virtual void update(){};
	virtual void draw(){};

	void mouseTrigger(int _type,int x,int y,int button);			//���ͳһ����
	void keyTrigger(int _type,int key);					//����ͳһ����

protected:

	//---------������------------
	virtual void mouseMoved(int x, int y,int button){};
	virtual void mouseDragged(int x, int y,int button){};
	virtual void mousePressed(int x, int y,int button){};
	virtual void mouseReleased(int x, int y,int button){};

	//---------���̲���------------
	virtual void keyPressed(int key){};
	virtual void keyReleased(int key){};
};

