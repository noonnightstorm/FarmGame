/*
 * BuildingsLayer.h
 *
 *  Created on: Feb 13, 2014
 *      Author: c860
 */
#include "BuildingsLayer.h"
#include "TouchListener.h"
#include "GameResources.h"

using namespace cocos2d;


BuildingsLayer::BuildingsLayer() {
	// TODO Auto-generated constructor stub

}

BuildingsLayer::~BuildingsLayer() {
	// TODO Auto-generated destructor stub
}

bool BuildingsLayer::init(){
	TouchListener::init();
	GameResources* res = GameResources::GetInstance();

	CCSize size;
	size.height = res->getWinHeight();
	size.width = res->getWinWidth();
	this->setContentSize(size);

	winSize = CCDirector::sharedDirector()->getVisibleSize();
	origin = CCDirector::sharedDirector()->getVisibleOrigin();
	CCSprite* canteen = CCSprite::create("canteen.png");
	canteen->setPosition( ccp(res->getRealWidth(7),res->getRealHeight(7)) );
	CCLog("%d %d",res->getRealHeight(15),res->getRealWidth(15));
	//	canteen->setPosition( ccp(origin.x + winSize.width/2, origin.y + winSize.height/2) );
	this->addChild(canteen);

	return true;
}
void BuildingsLayer::registerWithTouchDispatcher()
{
	TouchListener::registerWithTouchDispatcher();
}


bool BuildingsLayer::ccTouchBegan(CCTouch* touch, CCEvent* event)
{
	TouchListener::ccTouchBegan(touch,event);
	return true;
}

void BuildingsLayer::ccTouchMoved(CCTouch* touch, CCEvent* event)
{
	TouchListener::ccTouchMoved(touch,event);
}

void BuildingsLayer::ccTouchEnded(CCTouch* touch, CCEvent* event)
{
	TouchListener::ccTouchEnded(touch,event);
}
