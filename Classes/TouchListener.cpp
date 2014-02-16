/*
 * TouchListener.cpp
 *
 *  Created on: Feb 13, 2014
 *      Author: C860
 */

#include "TouchListener.h"
#include "GameBGLayer.h"


using namespace cocos2d;


TouchListener::TouchListener() {
	// TODO Auto-generated constructor stub

}

TouchListener::~TouchListener() {
	// TODO Auto-generated destructor stub
}

bool TouchListener::init(){
	if (!CCLayer::init() )
	{
		return false;
	}
	//设置为可点击
	this->setTouchEnabled(true);

	return true;
}
void TouchListener::registerWithTouchDispatcher()
{
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this,0,false);
}


bool TouchListener::ccTouchBegan(CCTouch* touch, CCEvent* event)
{
	beginPoint = touch->getLocation();
	return true;
}

void TouchListener::ccTouchMoved(CCTouch* touch, CCEvent* event)
{
	winSize = CCDirector::sharedDirector()->getVisibleSize();
	origin = CCDirector::sharedDirector()->getVisibleOrigin();

    //最大最小偏移
    int maxValue_top = origin.y + winSize.height/2 - (1007 - winSize.height)/2;
    int maxValue_bottom = origin.y + winSize.height/2 + (1007 - winSize.height)/2;
    int maxValue_left = origin.x + winSize.width/2 - (1000 - winSize.width)/2;
    int maxValue_right = origin.x + winSize.width/2 + (1000 - winSize.width)/2;

    CCLog("%d %d",winSize.height,winSize.width);
    CCLog("%d %d",maxValue_top,maxValue_bottom);
    CCLog("%d %d",maxValue_left,maxValue_right);

	endPoint = touch->getLocation();
	CCPoint MoveTo = ccpSub(endPoint,beginPoint);
	beginPoint = endPoint;

	CCPoint now_position =  this->getPosition();

	float now_x = now_position.x;
	float now_y = now_position.y;
	CCPoint result_postion = ccpAdd(now_position,MoveTo);
	//越界
	if(result_postion.x > maxValue_right || result_postion.x < maxValue_left){
		return;
	}
	else if(result_postion.y > maxValue_bottom || result_postion.y < maxValue_top){
		return;
	}

	this->setPosition(ccpAdd(now_position,MoveTo));
}

void TouchListener::ccTouchEnded(CCTouch* touch, CCEvent* event)
{
}
