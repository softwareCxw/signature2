#ifndef SIGNATURE_H_
#define SIGNATURE_H_

#include "ofMain.h"
#include "Pluxone_Basic.h"
#include "ofxDrawnetic.h"

class signature : public Pluxone_Basic
{
public:
	void setup();
	void update();
	void draw();

	//����ǩ������ͼ
	void setSignatureImg(ofImage img_temp)
	{
		img_signatureBack = img_temp;
		img_signatureBack.setAnchorPercent(.5, .5);
	}

	bool is_next()
	{
		if(b_next) {
			b_next =false;
			return true;
		}
		return false;
	}

	void revect();
private:
	void loadData();

	//������
	void mouseMoved(int x, int y);		
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
private:
	ofImage img_back;																//����ͼ
	ofImage img_color;																//��ɫѡ��ͼƬ
	ofVec2f pos_color;																//��ɫѡ��ͼƬ�Ļ���λ��
	ofRectangle rect_color_temp;												//��ɫʾ�����Ĵ�С��λ��
	ofImage img_signatureBack;													//ǩ������
	ofVec2f pos_signatureBack;													//ǩ������λ��

	ofImage img_save, img_last, img_delete;								//���浽���أ� ȥ����һ���ʼ���ɾ�������ʼ�
	ofVec2f pos_save, pos_last, pos_delete;

	//������һ������
	ofImage img_return;
	ofVec2f pos_return;

	bool b_sinature;																	//ǩ���߽����

	//ǩ������
	vector<ofxMarking *> markings;											//���бʼ��洢λ��
	ofxMarking * marking;															//�ʼ���ʱ�洢λ��
	ofColor color;																		//�ʴ���ɫ
	ofxTripPaint* paint;																		//�ʴ�
	ofxRibbonBrush* brush;
	ofxSuperPath* path;																//�ʼ�·���ʹ�С

	//������ת
	bool b_next;
};

#endif