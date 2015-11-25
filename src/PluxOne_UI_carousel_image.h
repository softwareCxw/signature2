#ifndef PLUXONE_UI_CAROUSEL_IMAGE_H_
#define PLUXONE_UI_CAROUSEL_IMAGE_H_

/*
	name  : cxw
	date    : 2015/4/22
	version: 0.1.0.150422
	action  : �ֲ�ͼƬ
	BeCarful : ����ͼƬ��Ĭ�����Ͻǻ���,��ͼƬ�ļ���ʽΪpng, ͼƬ��С���ͼ��صĵ�һ��ͼƬ�Ĵ�Сȫ��һ��
		update
	name : cxw
	 date : 2015/7/21
	 function : ��ӱ߽����
*/

#include "PluxOne_include.h"

class PluxOne_UI_carousel_image {
public :
	void setup(string _str_filePath, ofVec2f _pos_image, string _str_leftFilePath, ofVec2f _pos_left, string _str_rightFilePath, ofVec2f _pos_right);			//ͼƬĿ¼�� ͼƬ����λ�ã���߰�ťͼƬ·���� ��߰�ťͼƬ�Ļ���λ�ã� �ұ�ͼƬ·�����ұ�ͼƬ�Ļ���λ��
	void update();
	void draw();

	void mouseTrigger(int _type,int x,int y, int button);		//���ͳһ����  �������ͣ�

	void setRollSpeed(float rollSpeed)								//���ù����ٶ�
	{
		f_rollSpeed = rollSpeed;
	}

	int getSize()
	{
		return showImage.size();
	}

	int getCurrentImageId()
	{
		return i_currentImageShow;
	}

	ofImage getCurrentImg()
	{
		return showImage[i_currentImageShow];
	}

	void setDragSwitchMax(int dragMax)						//�����϶��л����ֵ
	{
		i_dragMax = dragMax;
	}

	void revect();

private :
	void loadImage()
	{
		ofDirectory dir;
		dir.open(str_filePath);
		dir.allowExt("png");
		dir.listDir();
		showImage.resize(dir.size());
		for(int i = 0; i != dir.size(); i ++)
		{
			showImage[i].loadImage(dir.getPath(i));
			showImage[i].resize(showImage[0].getWidth(), showImage[0].getHeight());
		}

		image_left.loadImage(str_fileLeft);
		image_right.loadImage(str_fileRight);
	}

	//������
	void mouseMoved(int x, int y);		
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
private :
	string str_filePath, str_fileLeft, str_fileRight;																				
	ofVec2f pos_image,pos_left, pos_right;																		
	ofImage image_left, image_right;
	vector<ofImage> showImage;

	int  i_currentImageShow, i_currentImage, i_currentImage2;										//�ƶ�֮����ʾͼƬ

	//�϶��л�ͼƬ
	int i_dragMax;												//�϶����ֵ
	int i_mousePressX, i_vaule;	
	bool b_drag;

	//���ƣ����Ƶı���
	int i_rightMove, i_leftMove;							//���ƣ�����
	bool b_leftMove, b_rightMove;						//���ƣ�����

	float f_rollSpeed;                                             //�����ٶ�
};

#endif