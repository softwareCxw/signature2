#pragma once

#include "ofMain.h"
#include "frame.h"

/*
    程序默认大小为1080p (1920 X 1080)
	F1 : 全屏
	F2 : 取消全屏
	F3：显示鼠标
	F4 ：隐藏鼠标
*/

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
		frame _f;
};
