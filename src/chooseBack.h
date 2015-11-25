#ifndef CHOOSEBACK_H_
#define CHOOSEBACK_H_

#include "ofMain.h"
#include "Pluxone_Basic.h"
#include "PluxOne_UI_carousel_image.h"

class chooseBack : public Pluxone_Basic
{
public:
	void setup();
	void update();
	void draw();

	//��ȡǩ������ͼ
	ofImage getSignatureImg()
	{
		return ui_chooseBack.getCurrentImg();
	}

	bool is_next()
	{
		if(b_next) {
			b_next = false;
			return true;
		}
		return false;
	}

	void revect();																	//����
private:
	void loadData();															//���ݼ���

	//������
	void mouseMoved(int x, int y);		
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
private:
	ofImage img_back;														//����ͼ
	ofImage img_next;														//��һ����ťͼ
	ofVec2f pos_next;															//��һ����ťͼ����

	ofImage img_yes, img_no;												//����ͼ
	vector<ofVec2f> pos_instruction;								//����ͼλ��

	bool b_next;

	PluxOne_UI_carousel_image ui_chooseBack;
};

#endif