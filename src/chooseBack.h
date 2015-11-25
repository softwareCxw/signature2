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

	//获取签名背景图
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

	void revect();																	//重置
private:
	void loadData();															//数据加载

	//鼠标操作
	void mouseMoved(int x, int y);		
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
private:
	ofImage img_back;														//背景图
	ofImage img_next;														//下一步按钮图
	ofVec2f pos_next;															//下一步按钮图坐标

	ofImage img_yes, img_no;												//索引图
	vector<ofVec2f> pos_instruction;								//索引图位置

	bool b_next;

	PluxOne_UI_carousel_image ui_chooseBack;
};

#endif