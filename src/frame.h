#ifndef FRAME_H_
#define FRAME_H_

#include "ofMain.h"
#include "Pluxone_Basic.h"

#include "chooseBack.h"								 //选择签名背景界面
#include "signature.h"									 //签名界面 

/*
	框架类，用于界面切换和两界面之间的数据传递
*/

class frame : public Pluxone_Basic {
public:
	enum Interface{CHOOSE=0, SIGNATURE};   //选择签名背景界面，签名界面
	void setup();
	void update();
	void draw();
private:

	//鼠标操作
	void mouseMoved(int x, int y);		
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
private:
     ofFbo _fbo;
	 int i_choose;													//界面选择

	 chooseBack _chooseBack;
	 signature _signature;
};

#endif