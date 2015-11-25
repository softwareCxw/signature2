#include "signature.h"

void signature::setup()
{
	loadData();

	path = new ofxSuperPath();
	path->setPathPressureType(OFX_PATH_PRESSURE_FIXED);
	path->setFixedThickness(5);
	path->reset();

	marking = NULL;
	brush = NULL;
	paint = NULL;

	color = ofColor(0, 0, 0);
	paint = new ofxTripPaint(path, color);
	paint->setDynamic(false);
}

void signature::update()
{
	if(marking != NULL)
	{
		marking->update();
	}
	for(int i = 0; i < markings.size(); i ++)
	{
		markings[i]->update();
	}
}

void signature::draw()
{
	//ofEnableBlendMode(OF_BLENDMODE_ALPHA);
	img_back.draw(0, 0);
	img_signatureBack.draw(pos_signatureBack);
	ofPushStyle();
	ofFill();
	ofSetColor(color);
	ofRect(rect_color_temp);
	ofPopStyle();
	img_color.draw(pos_color);

	for(int i = 0; i <markings.size(); i ++)
	{
		markings[i]->draw();
	}

	if(marking != NULL) {
		marking->draw();
	}

	img_delete.draw(pos_delete);
	img_save.draw(pos_save);
	img_last.draw(pos_last);

	img_return.draw(pos_return);
}

void signature::revect()
{
	b_sinature = false;
	b_next = false;

	marking = NULL;
	brush = NULL;
	paint = NULL;

	color = ofColor(0, 0, 0);
	paint = new ofxTripPaint(path, color);
	paint->setDynamic(false);

	if(markings.size() > 0) {
		vector<ofxMarking *>().swap(markings);
	}
}

void signature::loadData()
{
	img_back.loadImage(ofToDataPath("Img/signature/back.png"));
	img_color.loadImage(ofToDataPath("Img/signature/color.png"));
	img_color.setAnchorPercent(.5, .5);

	img_save.loadImage(ofToDataPath("Img/signature/save.png"));
	img_save.setAnchorPercent(.5, .5);
	img_delete.loadImage(ofToDataPath("Img/signature/delete.png"));
	img_delete.setAnchorPercent(.5, .5);
	img_last.loadImage(ofToDataPath(("Img/signature/last.png")));
	img_last.setAnchorPercent(.5, .5);
	
	img_return.loadImage(ofToDataPath("Img/signature/return.png"));
	img_return.setAnchorPercent(.5, .5);

	pos_color = ofVec2f(150, 400);
	rect_color_temp = ofRectangle(100, 200, 100, 20);
	pos_signatureBack = ofVec2f(1008, 432);

	pos_return = ofVec2f(img_return.getWidth() / 2, 1080 - img_return.getHeight() / 2);

	pos_save = ofVec2f(1920 / 2 + 50, 1000 - img_save.getHeight());
	pos_delete = ofVec2f(pos_save.x - img_delete.getWidth(), 1000 - img_delete.getHeight());
	pos_last = ofVec2f(pos_save.x + img_last.getWidth(), 1000 - img_last.getHeight());

	b_sinature = false;
	b_next = false;
}

void signature::mouseMoved( int x, int y )
{

}

void signature::mouseDragged( int x, int y, int button )
{
	if(abs(x - pos_signatureBack.x) < img_signatureBack.getWidth() / 2 && abs(y - pos_signatureBack.y) < img_signatureBack.getHeight() /2) {
		b_sinature = true;
		path->lineTo(x, y, 0, ofFloatColor(255), ofGetFrameNum(), 0);
	} else {
		b_sinature = false;
	}
}

void signature::mousePressed( int x, int y, int button )
{
	if(abs(x - pos_return.x) < img_return.getWidth() / 2 && abs(y - pos_return.y) < img_return.getHeight() / 2) {
		b_next = true;
	} else
	if(abs(x - pos_last.x) < img_last.getWidth() / 2 && abs(y - pos_last.y) < img_last.getHeight()  / 2) {
		if(markings.size() > 0) {
			markings.erase(markings.end() - 1);
		}
	} else if(abs(x - pos_delete.x) < img_delete.getWidth() / 2 && abs(y - pos_delete.y) < img_delete.getHeight() / 2) {
		if(markings.size() > 0) {
			vector<ofxMarking *>().swap(markings);
		}
	} else if(abs(x - pos_save.x) < img_save.getWidth() / 2 && abs(y - pos_save.y) < img_save.getHeight() / 2) {
		ofImage img_temp;
		float f_xProportion = ofGetWidth() / 1920.0;									//横轴的相对比例
		float f_yProportion = ofGetHeight() / 1080.0;									//纵轴的相对比例
		img_temp.grabScreen((pos_signatureBack.x - img_signatureBack.getWidth() / 2) * f_xProportion, (pos_signatureBack.y - img_signatureBack.getHeight() / 2) * f_yProportion, img_signatureBack.getWidth() * f_xProportion, img_signatureBack.getHeight() * f_yProportion);
		img_temp.saveImage(ofToDataPath("Img/save/" + ofToString(ofGetSystemTime()) + ".png"));
		img_temp.clear();
		b_next = true;
	} else {
		float f_distance = ofDist(x, y, pos_color.x, pos_color.y);
		if(f_distance < img_color.getWidth() / 2) {
			color = img_color.getColor(x - (pos_color.x - img_color.getWidth() / 2), y -(pos_color.y - img_color.getHeight() / 2));
			paint = new ofxTripPaint(path, color);
			paint->setDynamic(false);
		} else {
			if(abs(x - pos_signatureBack.x) < img_signatureBack.getWidth() / 2 && abs(y - pos_signatureBack.y) < img_signatureBack.getHeight() /2) {
				brush = new ofxRibbonBrush(path, paint);
				brush->setDynamic(false);
				brush->setSpeed(10);
				brush->setUseAcceleration(false);

				marking = new ofxMarking(path, paint, brush);
				path->reset();
				path->lineStart(x, y, 0, ofFloatColor(255), ofGetFrameNum(), 0);

				b_sinature = true;
			}
		}
	}
}

void signature::mouseReleased( int x, int y, int button )
{
	if(b_sinature) {
		if(abs(x - pos_signatureBack.x) < img_signatureBack.getWidth() / 2 && abs(y - pos_signatureBack.y) < img_signatureBack.getHeight() /2) {
			path->lineEnd(x, y, 0, ofGetFrameNum(), -1, 0);
			marking->pathFinished();
			markings.push_back(marking);
			marking = NULL;
			b_sinature = false;
		}
	} else {
		marking = NULL;
	}

}
