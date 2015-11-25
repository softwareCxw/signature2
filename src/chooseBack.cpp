#include "chooseBack.h"

void chooseBack::setup()
{
	loadData();

	ui_chooseBack.setup(ofToDataPath("Img/chooseBack/back"), ofVec2f(456, 303), ofToDataPath("Img/chooseBack/left.png"), ofVec2f(388, 566), ofToDataPath("Img/chooseBack/right.png"), ofVec2f(1510, 566));
	ui_chooseBack.setRollSpeed(50);

	//ÉèÖÃË÷ÒýÎ»ÖÃ
	pos_instruction.resize(ui_chooseBack.getSize());
	int i_xTemp = 980;
	int i_yTemp = 1000;
	int i_value = 20;
	for(int i = pos_instruction.size() / 2 - 1; i >= 0; i --)
	{
		pos_instruction[i].x = i_xTemp - (int)((i_value + img_no.getWidth() / 2) * abs((int)(pos_instruction.size() / 2 - i)));
		pos_instruction[i].y = i_yTemp;
	}
	for(int i = pos_instruction.size() / 2; i < pos_instruction.size(); i ++)
	{
		pos_instruction[i].x = i_xTemp + (i_value + img_no.getWidth() / 2) * abs((int)(pos_instruction.size() / 2 - i));
		pos_instruction[i].y = i_yTemp;
	}
}

void chooseBack::update()
{
	ui_chooseBack.update();
}

void chooseBack::draw()
{
	img_back.draw(0, 0);
	ui_chooseBack.draw();

	for(int i = 0; i < pos_instruction.size(); i ++)
	{
		img_no.draw(pos_instruction[i]);
		if(i == ui_chooseBack.getCurrentImageId()) {
			img_yes.draw(pos_instruction[i]);
		}
	}
	img_next.draw(pos_next);
}

void chooseBack::revect()
{
	ui_chooseBack.revect();
}

void chooseBack::loadData()
{
	img_back.loadImage(ofToDataPath("Img/chooseBack/back.png"));
	img_next.loadImage(ofToDataPath("Img/chooseBack/next.png"));
	img_next.setAnchorPercent(.5, .5);

	img_yes.loadImage(ofToDataPath("Img/chooseBack/yes.png"));
	img_yes.setAnchorPercent(.5, .5);
	img_no.loadImage(ofToDataPath("Img/chooseBack/no.png"));
	img_no.setAnchorPercent(.5, .5);

	pos_next = ofVec2f(1920 - img_next.getWidth() / 2, 1080 - img_next.getHeight() / 2);

	b_next = false;
}

void chooseBack::mouseMoved( int x, int y )
{

}

void chooseBack::mouseDragged( int x, int y, int button )
{
	ui_chooseBack.mouseTrigger(MOUSE_DRAGGED, x, y, button);
}

void chooseBack::mousePressed( int x, int y, int button )
{
	ui_chooseBack.mouseTrigger(MOUSE_PRESSED, x, y, button);
}

void chooseBack::mouseReleased( int x, int y, int button )
{
	ui_chooseBack.mouseTrigger(MOUSE_RELEASED, x, y, button);
	if(abs(x - pos_next.x) < img_next.getWidth() / 2 && abs(y - pos_next.y) < img_next.getHeight() / 2) {
		b_next = true;
	}
}
