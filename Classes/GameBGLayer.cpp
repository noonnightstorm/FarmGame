/*
 * GameBGLayer.cpp
 *
 *  Created on: Feb 10, 2014
 *      Author: noonnightstorm
 */

#include "GameBGLayer.h"
#include "TouchListener.h"
#include "cocos-ext.h"
#include "GameResources.h"

using namespace cocos2d;

using namespace cocos2d::extension;
using namespace cocos2d::gui;


GameBGLayer::GameBGLayer() {
	// TODO Auto-generated constructor stub

}

GameBGLayer::~GameBGLayer() {
	// TODO Auto-generated destructor stub
}

bool GameBGLayer::init(){
	TouchListener::init();

	//获取公共资源
	GameResources *resource = GameResources::GetInstance();

	//添加背景
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	bGSprite = CCSprite::create("background.png");
	bGSprite->setPosition( ccp(size.width/2, size.height/2) );

	resource->setWinHeight(bGSprite->getContentSize().height);
	resource->setWinWidth(bGSprite->getContentSize().width);
	resource->setMapLayer(this);

	this->addChild(bGSprite, 0);

	/*TouchGroup* ul =TouchGroup::create();
	ul->addWidget(GUIReader::shareReader()->widgetFromJsonFile("GameResourceUI_1/GameResourceUI_1.ExportJson"));
	this->addChild(ul,2);*/

	return true;
}
void GameBGLayer::registerWithTouchDispatcher()
{
	TouchListener::registerWithTouchDispatcher();
}


bool GameBGLayer::ccTouchBegan(CCTouch* touch, CCEvent* event)
{
	TouchListener::ccTouchBegan(touch,event);
	return true;
}

void GameBGLayer::ccTouchMoved(CCTouch* touch, CCEvent* event)
{
	TouchListener::ccTouchMoved(touch,event);
}

void GameBGLayer::ccTouchEnded(CCTouch* touch, CCEvent* event)
{
	TouchListener::ccTouchEnded(touch,event);
}
