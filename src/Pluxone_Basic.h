#pragma once
#include "PluxOne_include.h"

class Pluxone_Basic
{
public:
	Pluxone_Basic(void);
	~Pluxone_Basic(void);

	virtual void update(){};
	virtual void draw(){};

	void mouseTrigger(int _type,int x,int y,int button);			//鼠标统一输入
	void keyTrigger(int _type,int key);					//键盘统一输入

protected:

	//---------鼠标操作------------
	virtual void mouseMoved(int x, int y,int button){};
	virtual void mouseDragged(int x, int y,int button){};
	virtual void mousePressed(int x, int y,int button){};
	virtual void mouseReleased(int x, int y,int button){};

	//---------键盘操作------------
	virtual void keyPressed(int key){};
	virtual void keyReleased(int key){};
};

