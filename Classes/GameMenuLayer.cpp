/*
 * GameMenuLayer.cpp
 *
 *  Created on: Feb 11, 2014
 *      Author: noonnightstorm
 */

#include "GameMenuLayer.h"
#include "GameResources.h"
#include "TouchListener.h"
#include "cocos-ext.h"

using namespace cocos2d;
using namespace cocos2d::extension;
using namespace cocos2d::gui;

GameMenuLayer::GameMenuLayer() {
	// TODO Auto-generated constructor stub

}

GameMenuLayer::~GameMenuLayer() {
	// TODO Auto-generated destructor stub
}

bool GameMenuLayer::init() {
	CCLayer::init();
	//添加资源
	TouchGroup* ul =TouchGroup::create();
	ul->addWidget(GUIReader::shareReader()->widgetFromJsonFile("GameResourceUI_1/GameResourceUI_1.ExportJson"));
	this->addChild(ul,2);

	//初始化资源

	/*GameResources* resources = GameResources::GetInstance();
	CCLog("food : %d",resources->getFood());
	CCLog("money : %d",resources->getMoney());*/
	return true;
}
void GameMenuLayer::registerWithTouchDispatcher()
{
	TouchListener::registerWithTouchDispatcher();
}


bool GameMenuLayer::ccTouchBegan(CCTouch* touch, CCEvent* event)
{
	TouchListener::ccTouchBegan(touch,event);
	return true;
}

void GameMenuLayer::ccTouchMoved(CCTouch* touch, CCEvent* event)
{
	TouchListener::ccTouchMoved(touch,event);
}

void GameMenuLayer::ccTouchEnded(CCTouch* touch, CCEvent* event)
{
	TouchListener::ccTouchEnded(touch,event);
}

