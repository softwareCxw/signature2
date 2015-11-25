#ifndef FRAME_H_
#define FRAME_H_

#include "ofMain.h"
#include "Pluxone_Basic.h"

#include "chooseBack.h"								 //ѡ��ǩ����������
#include "signature.h"									 //ǩ������ 

/*
	����࣬���ڽ����л���������֮������ݴ���
*/

class frame : public Pluxone_Basic {
public:
	enum Interface{CHOOSE=0, SIGNATURE};   //ѡ��ǩ���������棬ǩ������
	void setup();
	void update();
	void draw();
private:

	//������
	void mouseMoved(int x, int y);		
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
private:
     ofFbo _fbo;
	 int i_choose;													//����ѡ��

	 chooseBack _chooseBack;
	 signature _signature;
};

#endif