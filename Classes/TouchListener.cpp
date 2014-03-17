/*
 * TouchListener.cpp
 *
 *  Created on: Feb 13, 2014
 *      Author: C860
 */

#include "TouchListener.h"
#include "GameBGLayer.h"
#include "GameResources.h"

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

	GameResources *resource = GameResources::GetInstance();
	float winHeight = resource->getWinHeight();
	float winWidth = resource->getWinWidth();
	CCLayer* mapLayer = resource->getMapLayer();

    //最大最小偏移
    float maxValue_top = origin.y + winSize.height/2 - (winHeight - winSize.height)/2;
    float maxValue_bottom = origin.y + winSize.height/2 + (winHeight - winSize.height)/2;
    float maxValue_left = origin.x + winSize.width/2 - (winWidth - winSize.width)/2;
    float maxValue_right = origin.x + winSize.width/2 + (winWidth - winSize.width)/2;

	endPoint = touch->getLocation();
	CCPoint MoveTo = ccpSub(endPoint,beginPoint);
	beginPoint = endPoint;

	CCPoint now_position =  mapLayer->getPosition();

	float now_x = now_position.x;
	float now_y = now_position.y;
	CCPoint result_position = ccpAdd(now_position,MoveTo);

	//横向越界处理
	if(result_position.x + mapLayer->getContentSize().width/2 > maxValue_right) {
		result_position.x = maxValue_right - mapLayer->getContentSize().width/2;
	}
	else if(result_position.x + mapLayer->getContentSize().width/2 < maxValue_left) {
		result_position.x = maxValue_left - mapLayer->getContentSize().width/2;
	}
	//纵向越界处理
	if(result_position.y + mapLayer->getContentSize().height/2 > maxValue_bottom) {
		result_position.y = maxValue_bottom - mapLayer->getContentSize().height/2;
	}
	else if(result_position.y + mapLayer->getContentSize().height/2 < maxValue_top) {
		result_position.y = maxValue_top - mapLayer->getContentSize().height/2;
	}

	this->setPosition(result_position);
}

void TouchListener::ccTouchEnded(CCTouch* touch, CCEvent* event)
{
}
