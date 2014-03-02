/*
 * AddBuildingLayer.cpp
 *
 *  Created on: Feb 26, 2014
 *      Author: C860
 */

#include "AddBuildingLayer.h"
#include "GameResources.h"
#include "TouchListener.h"
#include "cocos-ext.h"

using namespace cocos2d;
using namespace cocos2d::extension;
using namespace cocos2d::gui;

AddBuildingLayer::AddBuildingLayer() {
	// TODO Auto-generated constructor stub

}

AddBuildingLayer::~AddBuildingLayer() {
	// TODO Auto-generated destructor stub
}

bool AddBuildingLayer::init() {
	TouchListener::init();

	this->setTouchEnabled(false);

	CCSize winSize = CCDirector::sharedDirector()->getVisibleSize();
	CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

	CCSprite* techBuilding = CCSprite::create("teachBuilding.png");
	techBuilding->setPosition( ccp(origin.x + winSize.width/2, origin.y + winSize.height/2) );
	this->addChild(techBuilding);

	CCMenuItemImage* okBtn = CCMenuItemImage::create("button.png",
				"button.png",
				this,
				menu_selector(AddBuildingLayer::test));
	okBtn->setPosition(ccp(origin.x + okBtn->getContentSize().width/2,origin.y + okBtn->getContentSize().height/2));

	CCMenu* menu = CCMenu::create(okBtn,NULL);
	menu->setPosition(CCPointZero);
	this->addChild(menu,1,1);


	return true;
}
void AddBuildingLayer::registerWithTouchDispatcher()
{
	TouchListener::registerWithTouchDispatcher();
}


bool AddBuildingLayer::ccTouchBegan(CCTouch* touch, CCEvent* event)
{
	TouchListener::ccTouchBegan(touch,event);
	return true;
}

void AddBuildingLayer::ccTouchMoved(CCTouch* touch, CCEvent* event)
{
	TouchListener::ccTouchMoved(touch,event);
}

void AddBuildingLayer::ccTouchEnded(CCTouch* touch, CCEvent* event)
{
	TouchListener::ccTouchEnded(touch,event);
}
void AddBuildingLayer::test(CCObject *pSender)
{
	CCLog("test");
	this->removeChildByTag(1);
	this->setTouchEnabled(true);
}

