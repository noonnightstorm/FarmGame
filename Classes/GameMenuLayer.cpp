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
#include "Building.h"
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
	if (!CCLayer::init())
	{
		return false;
	}
	//设置为可点击
	this->setTouchEnabled(true);

	winSize = CCDirector::sharedDirector()->getVisibleSize();
	origin = CCDirector::sharedDirector()->getVisibleOrigin();

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
void GameMenuLayer::showMenu(CCObject *pSender, TouchEventType type)
{
	if(type == TOUCH_EVENT_ENDED){

		menu = TouchGroup::create();
		menu->addWidget(GUIReader::shareReader()->widgetFromJsonFile("Menu/Menu.json"));

		m_widget = static_cast<UIWidget*>(menu->getWidgetByName("Panel_1"));

		m_backBtn = static_cast<UIButton*>(m_widget->getChildByName("backBtn"));
		m_backBtn->setTouchEnabled(true);
		m_backBtn->addTouchEventListener(this,toucheventselector(GameMenuLayer::closeMenu));

		m_b1 = static_cast<UIButton*>(m_widget->getChildByName("canteen"));
		m_b1->setTouchEnabled(true);
		m_b1->addTouchEventListener(this,toucheventselector(GameMenuLayer::addBuilding));

		m_b2 = static_cast<UIButton*>(m_widget->getChildByName("teachBuilding"));
		m_b2->setTouchEnabled(true);
		m_b2->addTouchEventListener(this,toucheventselector(GameMenuLayer::addBuilding));

		m_b3 = static_cast<UIButton*>(m_widget->getChildByName("dormitory_stu"));
		m_b3->setTouchEnabled(true);
		m_b3->addTouchEventListener(this,toucheventselector(GameMenuLayer::addBuilding));

		m_b4 = static_cast<UIButton*>(m_widget->getChildByName("dormitory_worker"));
		m_b4->setTouchEnabled(true);
		m_b4->addTouchEventListener(this,toucheventselector(GameMenuLayer::addBuilding));

		this->addChild(menu,2,8);
	}
}
void GameMenuLayer::closeMenu(CCObject *pSender, TouchEventType type)
{
	this->removeChildByTag(8);
}
void GameMenuLayer::addBuilding(CCObject *pSender, TouchEventType type)
{

	GameResources* resource = GameResources::GetInstance();
	CCSize mapSize;
	mapSize.height = resource->getWinHeight();
	mapSize.width = resource->getWinWidth();

	this->removeChildByTag(8);

	temp = AddBuildingLayer::create();
	temp->setContentSize(mapSize);

	this->addChild(temp,5,99);

	ccColor4B color = ccc4(220, 220, 220, 150);
	CCLayerColor* color_layer = CCLayerColor::create(color);
	color_layer->setPosition(ccp(0,0));
	color_layer->setContentSize(mapSize);

	this->addChild(color_layer,6,100);

	if(pSender==m_b1) {
		resource->setNewBuildingName("canteen.png");
	}
	else if(pSender==m_b2) {
		resource->setNewBuildingName("teachBuilding.png");
	}
	else if(pSender==m_b3) {
		resource->setNewBuildingName("dormitory_stu.png");
	}
	else if(pSender==m_b4) {
		resource->setNewBuildingName("dormitory_worker.png");
	}

	CCNotificationCenter::sharedNotificationCenter()->addObserver(this,callfuncO_selector(GameMenuLayer::getNewPosition),"newBuilding",NULL);

	CCNotificationCenter::sharedNotificationCenter()->addObserver(this,callfuncO_selector(GameMenuLayer::finishBuild),"newPositionFinish",NULL);
}
void GameMenuLayer::getNewPosition(CCObject* obj)
{
	GameResources* res = GameResources::GetInstance();

	CCSprite* p = (CCSprite*)obj;
	CCPoint point = p->getPosition();
	if(res->getPosValue(point.x/45, point.y/45)==0) {
		res->setPosValue(point.x/45, point.y/45, 1);
		Building* building = Building::create(res->getNewBuildingName());
		building->setPosition(point);
		res->getBuildingLayer()->addChild(building,5);
		CCNotificationCenter::sharedNotificationCenter()->postNotification("newPositionFinish",(CCObject*)1);
	}
	else {
//		CCMessageBox("你选择的地方已经被占用啦！","提示");
		CCLabelTTF* tips = CCLabelTTF::create("你选择的地方已经被占用，请重新选择", "Marker Felt", 16);

		ccColor3B textcolor = {220, 220, 220};
		tips->setColor(textcolor);

		tips->setPosition(ccp(origin.x + winSize.width/2,origin.y + winSize.height/2 + 50));
		temp->addChild(tips,5,101);
		scheduleOnce(schedule_selector(GameMenuLayer::closeTips), 0.5f);
	}
}
void GameMenuLayer::finishBuild(CCObject* obj)
{
	this->removeChildByTag(99);
	this->removeChildByTag(100);
}
void GameMenuLayer::closeTips()
{
	temp->removeChildByTag(101);
}
