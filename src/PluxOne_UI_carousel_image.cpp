#include "PluxOne_UI_carousel_image.h"

void PluxOne_UI_carousel_image::setup(string _str_filePath, ofVec2f _pos_image, string _str_leftFilePath, ofVec2f _pos_left, string _str_rightFilePath, ofVec2f _pos_right)
{
	str_filePath = _str_filePath;
	pos_image = _pos_image;
	str_fileLeft = _str_leftFilePath;
	pos_left = _pos_left;
	str_fileRight = _str_rightFilePath;
	pos_right = _pos_right;

	loadImage();

	i_dragMax = showImage[0].getWidth() / 2;

	f_rollSpeed = 33;

	i_currentImage = 0;
	i_currentImage2 = 0;
	i_currentImageShow = 0;
	i_mousePressX = 0;
	i_vaule = 0;
	b_drag = false;
	i_leftMove = 0;
	i_rightMove = 0;
	b_leftMove = false;
	b_rightMove = false;
}

void PluxOne_UI_carousel_image::update()
{
	if(b_leftMove) {
		if(i_leftMove  + f_rollSpeed < showImage[i_currentImage].getWidth()) {
			i_leftMove += f_rollSpeed;
		} else {
			b_leftMove = false;
			i_leftMove = showImage[i_currentImage].getWidth();

			
			i_leftMove = 0;
			i_currentImageShow = i_currentImage2;
		}
	} else if(b_rightMove) {
		
		if(i_rightMove + f_rollSpeed < showImage[i_currentImage].getWidth()) {
			i_rightMove += f_rollSpeed;
		} else {
			b_rightMove = false;
			i_rightMove = showImage[i_currentImage].getWidth();

			i_currentImageShow = i_currentImage2;
			
			i_rightMove = 0;
		}
	}
}

void PluxOne_UI_carousel_image::draw()
{
	if(b_leftMove) {
		showImage[i_currentImage].drawSubsection(pos_image.x, pos_image.y, showImage[i_currentImage].getWidth() - i_leftMove, showImage[i_currentImage].getHeight(), 0 + i_leftMove,0, showImage[i_currentImage].getWidth() - i_leftMove, showImage[i_currentImage].getHeight());
		showImage[i_currentImage2].drawSubsection(pos_image.x + showImage[0].getWidth() - i_leftMove, pos_image.y, i_leftMove, showImage[i_currentImage2].getHeight(), 0,0, i_leftMove, showImage[i_currentImage2].getHeight());
	} else if(b_rightMove) {
		showImage[i_currentImage].drawSubsection(pos_image.x + i_rightMove, pos_image.y, showImage[i_currentImage].getWidth() - i_rightMove, showImage[i_currentImage].getHeight(), 0, 0, showImage[i_currentImage].getWidth() - i_rightMove, showImage[i_currentImage].getHeight());
		showImage[i_currentImage2].drawSubsection(pos_image.x, pos_image.y, i_rightMove, showImage[i_currentImage2].getHeight(), 0 + showImage[i_currentImage2].getWidth() - i_rightMove, 0, i_rightMove, showImage[i_currentImage2].getHeight());
	} else {
		showImage[i_currentImageShow].draw(pos_image.x, pos_image.y);
	}
	
	image_left.draw(pos_left.x, pos_left.y);
	image_right.draw(pos_right.x, pos_right.y);
}

void PluxOne_UI_carousel_image::mouseTrigger(int _type,int x,int y, int button)
{
	switch(_type)
	{
	case MOUSE_PRESSED:
		mousePressed(x, y, button);
		break;
	case MOUSE_MOVED:
		mouseMoved(x, y);
		break;
	case MOUSE_DRAGGED:
		mouseDragged(x, y, button);
		break;
	case MOUSE_RELEASED :
		mouseReleased(x, y, button);
		break;
	default:
		break;
	}
}

void PluxOne_UI_carousel_image::revect()
{
	i_currentImage = 0;
	i_currentImage2 = 0;
	i_currentImageShow = 0;
	i_mousePressX = 0;
	i_vaule = 0;
	b_drag = false;
	i_leftMove = 0;
	i_rightMove = 0;
	b_leftMove = false;
	b_rightMove = false;
}

void PluxOne_UI_carousel_image::mousePressed(int x, int y, int button)
{
	if(!b_leftMove && !b_rightMove && !b_drag) {
		if(x > pos_left.x && x < pos_left.x + image_left.getWidth() && 
			y > pos_left.y && y < pos_left.y + image_left.getHeight()) {	
				if(i_currentImage2 > 0) {
					b_rightMove = true;
					i_currentImage = i_currentImage2;
					i_currentImage2 = i_currentImage - 1;
				}
		} else if(x > pos_right.x && x < pos_right.x + image_right.getWidth() && 
			y > pos_right.y && y < pos_right.y + image_right.getHeight()) {
				if(i_currentImage2 < showImage.size() - 1) {
					b_leftMove = true;
					i_currentImage = i_currentImage2;
					i_currentImage2 = i_currentImage + 1;
				}
		} else if(x > pos_image.x && x < pos_image.x + showImage[i_currentImageShow].getWidth() &&
			y > pos_image.y && y < pos_image.y + showImage[i_currentImageShow].getHeight()) {
				b_drag = true;
				i_mousePressX = x;
		}
	}
	
}

void PluxOne_UI_carousel_image::mouseDragged(int x, int y, int button)
{
	if(b_drag) {
		i_vaule = x - i_mousePressX;
	}
}

void PluxOne_UI_carousel_image::mouseReleased(int x, int y, int button)
{
	if(b_drag) {
		if(i_vaule < 0) {
			if(abs(i_vaule) > i_dragMax) {
				
				if(i_currentImage2 < showImage.size() - 1) {
					b_leftMove = true;
					i_currentImage = i_currentImage2;
					i_currentImage2 = i_currentImage + 1;
				}
			}
		} else if(i_vaule > 0) {
			if(abs(i_vaule) > i_dragMax) {
				if(i_currentImage2 > 0) {
					b_rightMove = true;
					i_currentImage = i_currentImage2;
					i_currentImage2 = i_currentImage - 1;
				}
			}
		}
		b_drag = false;
		i_vaule  = 0;
	}
}

void PluxOne_UI_carousel_image::mouseMoved(int x, int y)
{

}