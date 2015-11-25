#pragma once

#include "ofMain.h"
#include "frame.h"

/*
    ����Ĭ�ϴ�СΪ1080p (1920 X 1080)
	F1 : ȫ��
	F2 : ȡ��ȫ��
	F3����ʾ���
	F4 ���������
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
