/*
 * TouchListener.cpp
 *
 *  Created on: Feb 13, 2014
 *      Author: C860
 */

#include "TouchListener.h"
#include "GameBGLayer.h"
#include "Global.h"


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
    float maxValue_top = origin.y + winSize.height/2 - (winHeight - winSize.height)/2;
    float maxValue_bottom = origin.y + winSize.height/2 + (winHeight - winSize.height)/2;
    float maxValue_left = origin.x + winSize.width/2 - (winWidth - winSize.width)/2;
    float maxValue_right = origin.x + winSize.width/2 + (winWidth - winSize.width)/2;

	endPoint = touch->getLocation();
	CCPoint MoveTo = ccpSub(endPoint,beginPoint);
	beginPoint = endPoint;

	CCPoint now_position =  this->getPosition();

	float now_x = now_position.x;
	float now_y = now_position.y;
	CCPoint result_postion = ccpAdd(now_position,MoveTo);

	//越界
	if(result_postion.x + this->getContentSize().width/2 > maxValue_right || result_postion.x + this->getContentSize().width/2 < maxValue_left){
		CCLog("out!");
		return;
	}
	else if(result_postion.y + this->getContentSize().height/2 > maxValue_bottom || result_postion.y + this->getContentSize().height/2 < maxValue_top){
		CCLog("out!");
		return;
	}

	CCLog("in!");
	this->setPosition(ccpAdd(now_position,MoveTo));
}

void TouchListener::ccTouchEnded(CCTouch* touch, CCEvent* event)
{
}
