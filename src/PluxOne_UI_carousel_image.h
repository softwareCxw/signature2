#ifndef PLUXONE_UI_CAROUSEL_IMAGE_H_
#define PLUXONE_UI_CAROUSEL_IMAGE_H_

/*
	name  : cxw
	date    : 2015/4/22
	version: 0.1.0.150422
	action  : 轮播图片
	BeCarful : 所有图片是默认左上角绘制,且图片文件格式为png, 图片大小，和加载的第一张图片的大小全部一样
		update
	name : cxw
	 date : 2015/7/21
	 function : 添加边界控制
*/

#include "PluxOne_include.h"

class PluxOne_UI_carousel_image {
public :
	void setup(string _str_filePath, ofVec2f _pos_image, string _str_leftFilePath, ofVec2f _pos_left, string _str_rightFilePath, ofVec2f _pos_right);			//图片目录， 图片绘制位置，左边按钮图片路径， 左边按钮图片的绘制位置， 右边图片路径，右边图片的绘制位置
	void update();
	void draw();

	void mouseTrigger(int _type,int x,int y, int button);		//鼠标统一输入  操作类型，

	void setRollSpeed(float rollSpeed)								//设置滚动速度
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

	void setDragSwitchMax(int dragMax)						//设置拖动切换最大值
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

	//鼠标操作
	void mouseMoved(int x, int y);		
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
private :
	string str_filePath, str_fileLeft, str_fileRight;																				
	ofVec2f pos_image,pos_left, pos_right;																		
	ofImage image_left, image_right;
	vector<ofImage> showImage;

	int  i_currentImageShow, i_currentImage, i_currentImage2;										//移动之后显示图片

	//拖动切换图片
	int i_dragMax;												//拖动最大值
	int i_mousePressX, i_vaule;	
	bool b_drag;

	//左移，右移的变量
	int i_rightMove, i_leftMove;							//右移，左移
	bool b_leftMove, b_rightMove;						//左移，右移

	float f_rollSpeed;                                             //滚动速度
};

#endif