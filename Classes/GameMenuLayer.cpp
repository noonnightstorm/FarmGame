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
	if (!CCLayer::init() )
	{
		return false;
	}
	//设置为可点击
	this->setTouchEnabled(true);

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
	menu_btn = static_cast<UIButton*>(widget->getChildByName("menu"));
	menu_btn->setTouchEnabled(true);
	menu_btn->addTouchEventListener(this,toucheventselector(GameMenuLayer::showMenu));


	//定时器
	this->schedule(schedule_selector(GameMenuLayer::foodConsume),60);

	return true;
}
/*void GameMenuLayer::registerWithTouchDispatcher()
{
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this,0,false);
}


bool GameMenuLayer::ccTouchBegan(CCTouch* touch, CCEvent* event)
{
	CCLog("begin!!!");
	return true;
}*/

/*void GameMenuLayer::ccTouchMoved(CCTouch* touch, CCEvent* event)
{
	TouchListener::ccTouchMoved(touch,event);
}

void GameMenuLayer::ccTouchEnded(CCTouch* touch, CCEvent* event)
{
	TouchListener::ccTouchEnded(touch,event);
}*/
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
void GameMenuLayer::showMenu(CCObject *pSender, TouchEventType type)
{
	if(type == TOUCH_EVENT_ENDED){

		if(pSender==menu_btn) {
			CCLog("yes!");
		}

		menu = TouchGroup::create();
		menu->addWidget(GUIReader::shareReader()->widgetFromJsonFile("Menu/Menu.json"));

		this->addChild(menu,3,8);

		UIWidget* m_widget = static_cast<UIWidget*>(menu->getWidgetByName("Panel_1"));

		UIButton* m_backBtn = static_cast<UIButton*>(m_widget->getChildByName("backBtn"));
		m_backBtn->setTouchEnabled(true);
		m_backBtn->addTouchEventListener(this,toucheventselector(GameMenuLayer::closeMenu));
	}
}
void GameMenuLayer::closeMenu(CCObject *pSender, TouchEventType type)
{
	this->removeChildByTag(8);
}
