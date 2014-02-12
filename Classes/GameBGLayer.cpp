/*
 * GameBGLayer.cpp
 *
 *  Created on: Feb 10, 2014
 *      Author: noonnightstorm
 */

#include "GameBGLayer.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;


using namespace cocos2d;


GameBGLayer::GameBGLayer() {
	// TODO Auto-generated constructor stub

}

GameBGLayer::~GameBGLayer() {
	// TODO Auto-generated destructor stub
}

bool GameBGLayer::init(){
	//设置为可点击
	if (!CCLayer::init() )
	{
		return false;
	}
	this->setTouchEnabled(true);
	//添加背景
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	bGSprite = CCSprite::create("background.png");
	bGSprite->setPosition( ccp(size.width/2, size.height/2) );
	this->addChild(bGSprite, 0);
	return true;
}
void GameBGLayer::registerWithTouchDispatcher()
{
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this,0,true);
}


bool GameBGLayer::ccTouchBegan(CCTouch* touch, CCEvent* event)
{
	beginPoint = touch->getLocation();
	return true;
}

void GameBGLayer::ccTouchMoved(CCTouch* touch, CCEvent* event)
{

	endPoint = touch->getLocation();
	CCPoint MoveTo = ccpSub(endPoint,beginPoint);
	beginPoint = endPoint;

	CCPoint now_position =  bGSprite->getPosition();
	float now_x = now_position.x;
	float now_y = now_position.y;
	CCPoint result_postion = ccpAdd(now_position,MoveTo);
	//越界
	if(result_postion.x > 395 || result_postion.x < 85){
		return;
	}
	else if(result_postion.y > 435 || result_postion.y < -115){
		return;
	}

	bGSprite->setPosition(ccpAdd(now_position,MoveTo));
	CCLog("x : %f  |  y : %f",result_postion.x,result_postion.y);
}

void GameBGLayer::ccTouchEnded(CCTouch* touch, CCEvent* event)
{
}
