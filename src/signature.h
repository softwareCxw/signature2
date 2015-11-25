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

	//设置签名背景图
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

	//鼠标操作
	void mouseMoved(int x, int y);		
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
private:
	ofImage img_back;																//背景图
	ofImage img_color;																//颜色选择图片
	ofVec2f pos_color;																//颜色选择图片的绘制位置
	ofRectangle rect_color_temp;												//颜色示意区的大小和位置
	ofImage img_signatureBack;													//签名背景
	ofVec2f pos_signatureBack;													//签名背景位置

	ofImage img_save, img_last, img_delete;								//保存到本地， 去除上一个笔迹，删除整个笔迹
	ofVec2f pos_save, pos_last, pos_delete;

	//返回上一个界面
	ofImage img_return;
	ofVec2f pos_return;

	bool b_sinature;																	//签名边界控制

	//签名所需
	vector<ofxMarking *> markings;											//所有笔迹存储位置
	ofxMarking * marking;															//笔迹临时存储位置
	ofColor color;																		//笔触颜色
	ofxTripPaint* paint;																		//笔触
	ofxRibbonBrush* brush;
	ofxSuperPath* path;																//笔迹路径和大小

	//界面跳转
	bool b_next;
};

#endif