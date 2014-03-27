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
#include "Building/Building.h"
#include "Building/Canteen.h"
#include "Building/ClassRoom.h"
#include "Building/DormitoryStu.h"
#include "Building/DormitoryWrk.h"
#include "Building/BuildObject.h"
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
	worker_free_num_label = static_cast<UILabelAtlas*>(widget->getChildByName("worker_free_num"));
	worker_free_num_label->setStringValue("2");
	student_free_num_label = static_cast<UILabelAtlas*>(widget->getChildByName("student_free_num"));
	student_free_num_label->setStringValue("2");
	worker_total_num_label = static_cast<UILabelAtlas*>(widget->getChildByName("worker_totle_num"));
	worker_total_num_label->setStringValue("5");
	student_total_num_label = static_cast<UILabelAtlas*>(widget->getChildByName("student_totle_num"));
	student_total_num_label->setStringValue("5");
	menu_btn = static_cast<UIButton*>(widget->getChildByName("menu"));
	menu_btn->setTouchEnabled(true);
	menu_btn->addTouchEventListener(this,toucheventselector(GameMenuLayer::showMenu));


	//定时器
	this->schedule(schedule_selector(GameMenuLayer::foodConsume),60);

	return true;
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
void GameMenuLayer::showMenu(CCObject *pSender, TouchEventType type)
{
	if(type == TOUCH_EVENT_ENDED){

		this->removeChildByTag(8);

		menu = TouchGroup::create();
		menu->addWidget(GUIReader::shareReader()->widgetFromJsonFile("Menu/Menu.json"));

		m_widget = static_cast<UIWidget*>(menu->getWidgetByName("Panel_1"));

		m_backBtn = static_cast<UIButton*>(m_widget->getChildByName("backBtn"));
		m_backBtn->setTouchEnabled(true);
		m_backBtn->addTouchEventListener(this,toucheventselector(GameMenuLayer::closeMenu));

		m_b1 = static_cast<UIButton*>(m_widget->getChildByName("canteen"));
		m_b1->setTouchEnabled(true);
		m_b1->addTouchEventListener(this,toucheventselector(GameMenuLayer::showConfirmMenu));

		m_b2 = static_cast<UIButton*>(m_widget->getChildByName("teachBuilding"));
		m_b2->setTouchEnabled(true);
		m_b2->addTouchEventListener(this,toucheventselector(GameMenuLayer::showConfirmMenu));

		m_b3 = static_cast<UIButton*>(m_widget->getChildByName("dormitory_stu"));
		m_b3->setTouchEnabled(true);
		m_b3->addTouchEventListener(this,toucheventselector(GameMenuLayer::showConfirmMenu));

		m_b4 = static_cast<UIButton*>(m_widget->getChildByName("dormitory_worker"));
		m_b4->setTouchEnabled(true);
		m_b4->addTouchEventListener(this,toucheventselector(GameMenuLayer::showConfirmMenu));

		this->addChild(menu,2,8);
	}
}
void GameMenuLayer::closeMenu(CCObject *pSender, TouchEventType type)
{
	this->removeChildByTag(8);
}
void GameMenuLayer::addBuilding()
{

	GameResources* resource = GameResources::GetInstance();
	CCSize mapSize;
	mapSize.height = resource->getWinHeight();
	mapSize.width = resource->getWinWidth();

	temp = AddBuildingLayer::create();
	temp->setContentSize(mapSize);

	temp->setBuildingStr(bType);

	this->addChild(temp,5,99);

	CCNotificationCenter::sharedNotificationCenter()->addObserver(this,callfuncO_selector(GameMenuLayer::getNewPosition),"newBuilding",NULL);

	CCNotificationCenter::sharedNotificationCenter()->addObserver(this,callfuncO_selector(GameMenuLayer::finishBuild),"newPositionFinish",NULL);
}


void GameMenuLayer::showConfirmMenu(CCObject *pSender, TouchEventType type)
{
	this->removeChildByTag(8);

	TouchGroup* infoMenu = TouchGroup::create();
	infoMenu->addWidget(GUIReader::shareReader()->widgetFromJsonFile("InfoMenu/InfoMenu.json"));

	this->addChild(infoMenu,5,100);

	UIWidget* im_widget = static_cast<UIWidget*>(infoMenu->getWidgetByName("Panel_1"));

	UIImageView* im_buildingView = static_cast<UIImageView*>(im_widget->getChildByName("buildingView"));

	if(pSender==m_b1) {
		im_buildingView->loadTexture("canteen.png");
		bType = "Canteen";
		initConfirmMenu("简介","100","50","4",infoMenu);
	}
	else if(pSender==m_b2) {
		im_buildingView->loadTexture("teachBuilding.png");
		bType = "ClassRoom";
		initConfirmMenu("简介","150","20","8",infoMenu);
	}
	else if(pSender==m_b3) {
		im_buildingView->loadTexture("dormitory_stu.png");
		bType = "DormitoryStu";
		initConfirmMenu("简介","60","10","4",infoMenu);
	}
	else if(pSender==m_b4) {
		im_buildingView->loadTexture("dormitory_worker.png");
		bType = "DormitoryWrk";
		initConfirmMenu("简介","50","50","4",infoMenu);
	}

	UIButton* im_crossBtn = static_cast<UIButton*>(infoMenu->getWidgetByName("crossBtn"));
	im_crossBtn->setTouchEnabled(true);
	im_crossBtn->addTouchEventListener(this,toucheventselector(GameMenuLayer::cancelAddBuilding));

	UIButton* im_tickBtn = static_cast<UIButton*>(infoMenu->getWidgetByName("tickBtn"));
	im_tickBtn->setTouchEnabled(true);
	im_tickBtn->addTouchEventListener(this,toucheventselector(GameMenuLayer::confirmAddBuilding));
}

void GameMenuLayer::confirmAddBuilding()
{
	this->removeChildByTag(100);

	addBuilding();
}

void GameMenuLayer::cancelAddBuilding()
{
	this->removeChildByTag(100);
}

void GameMenuLayer::getNewPosition(CCObject* obj)
{
	//这里还需要看看够不够人手

	GameResources* res = GameResources::GetInstance();
	BuildObject* bobj = (BuildObject*)obj;
	CCPoint point = bobj->getPosition();
	if(res->getPosValue(point.x/45, point.y/45) == 0) {
		Building* building;
		if(bobj->getBuildingStr().compare("Canteen") == 0){
			building = Canteen::create();
		}
		else if(bobj->getBuildingStr().compare("ClassRoom") == 0){
			building = ClassRoom::create();
		}
		else if(bobj->getBuildingStr().compare("DormitoryStu") == 0){
			building = DormitoryStu::create();
		}
		else if(bobj->getBuildingStr().compare("DormitoryWrk") == 0){
			building = DormitoryWrk::create();
		}
		building->doBuilding((int)((int)point.x/45),(int)((int)point.y/45));
		res->getBuildingLayer()->addChild(building,5);
		res->addBuildingIndex();
		CCNotificationCenter::sharedNotificationCenter()->postNotification("newPositionFinish",(CCObject*)1);
	}
	else {
		CCLabelTTF* tips = CCLabelTTF::create("你选择的地方已经被占用，请重新选择", "Marker Felt", 16);
		ccColor3B textcolor = {220, 220, 220};
		tips->setColor(textcolor);

		tips->setPosition(ccp(origin.x + winSize.width/2,origin.y + winSize.height/2 + 50));
		temp->addChild(tips,5,101);
		scheduleOnce(schedule_selector(GameMenuLayer::closeTips), 1);
	}
}
void GameMenuLayer::finishBuild(CCObject* obj)
{
	this->removeChildByTag(99);
//	this->removeChildByTag(100);
}
void GameMenuLayer::closeTips()
{
	temp->removeChildByTag(101);
}
void GameMenuLayer::initConfirmMenu(string about, string price, string wood, string maxPeople, TouchGroup* menu)
{
	UILabel* l_about = static_cast<UILabel*>(menu->getWidgetByName("about"));
	UILabel* l_price = static_cast<UILabel*>(menu->getWidgetByName("price"));
	UILabel* l_wood = static_cast<UILabel*>(menu->getWidgetByName("wood"));
	UILabel* l_maxPeople = static_cast<UILabel*>(menu->getWidgetByName("people"));

	l_about->setText(about);
	l_price->setText(price);
	l_wood->setText(wood);
	l_maxPeople->setText(maxPeople);
}
