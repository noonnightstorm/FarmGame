/*
 * GameMenuLayer.cpp
 *
 *  Created on: Feb 11, 2014
 *      Author: noonnightstorm
 */
#include <iostream>
#include <string>
#include "GameMenuLayer.h"
#include "GameResources.h"
#include "TouchListener.h"
#include "AddBuildingLayer.h"
#include "cocos-ext.h"

using namespace std;
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
	ul = TouchGroup::create();
	ul->addWidget(GUIReader::shareReader()->widgetFromJsonFile("GameResourceUI/GameResourceUI_1.ExportJson"));
	this->addChild(ul,2);
	//先初始化一些数据
	widget = static_cast<UIWidget*>(ul->getWidgetByName("Panel_20"));
	food_num_label = static_cast<UILabelAtlas*>(widget->getChildByName("food_num"));
	food_num_label->setStringValue("150");
	money_num_label = static_cast<UILabelAtlas*>(widget->getChildByName("money_num"));
	money_num_label->setStringValue("150");
	worker_num_label = static_cast<UILabelAtlas*>(widget->getChildByName("worker_num"));
	worker_num_label->setStringValue("2");
	student_num_label = static_cast<UILabelAtlas*>(widget->getChildByName("student_num"));
	student_num_label->setStringValue("2");

	//定时器
	this->schedule(schedule_selector(GameMenuLayer::foodConsume),60);

	//添加菜单层
	CCMenu* menu = CCMenu::create();
	menu->setPosition(CCPointZero);
	CCSprite* menuBg = CCSprite::create("menu.png");
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	menuBg->setPosition(ccp(size.width/2,size.height/2));
	menu->addChild(menuBg,0);

	CCMenuItemImage* teachBuilding = CCMenuItemImage::create(
	    "teachBuilding.png",
	    "teachBuilding.png",
	    this,
	    menu_selector(GameMenuLayer::addTeachBuilding));
	teachBuilding->setPosition(ccp(180,200));

	menu->addChild(teachBuilding,1);

	CCMenuItemImage* cantBuilding = CCMenuItemImage::create(
		    "canteen.png",
		    "canteen.png",
		    this,
		    menu_selector(GameMenuLayer::addCanteenBuilding));
	cantBuilding->setPosition(ccp(300,200));

	menu->addChild(cantBuilding,1);

	CCMenuItemImage* cancelBtn = CCMenuItemImage::create(
			    "cancel.png",
			    "cancel.png",
			    this,
			    menu_selector(GameMenuLayer::closeMenu));
	cancelBtn->setPosition(ccp(350,80));

	menu->addChild(cancelBtn,1);

	this->addChild(menu,3,8);


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
void GameMenuLayer::foodConsume(float dt)
{
	GameResources *resource = GameResources::GetInstance();
	int people_num = resource->getPeople();
	char const* old_food_string = food_num_label->getStringValue();
	int new_food = atoi(old_food_string) - people_num * 3;
	resource->setFood(new_food);
	char temp_food_char[100];
	sprintf(temp_food_char, "%d", new_food);
	food_num_label->setStringValue(temp_food_char);
	//CCLog("Now_Food: %d",new_food);
}
void GameMenuLayer::addTeachBuilding(CCObject *pSender, TouchEventType type)
{
	this->removeChildByTag(8);
	CCLayer* ABLayer = AddBuildingLayer::create();
	this->addChild(ABLayer,3);
}
void GameMenuLayer::addCanteenBuilding(CCObject *pSender, TouchEventType type)
{
	CCLog("click!");
}
void GameMenuLayer::closeMenu(CCObject *pSender, TouchEventType type)
{
	this->removeChildByTag(8);
}
