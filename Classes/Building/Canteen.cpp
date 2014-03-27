/*
 * Canteen.cpp
 *
 *  Created on: Mar 19, 2014
 *      Author: noonnightstorm
 */

#include "Canteen.h"
#include "cocos-ext.h"
#include "Building.h"
#include "People/CookMan.h"

using namespace cocos2d;
using namespace cocos2d::extension;
using namespace cocos2d::gui;

Canteen::Canteen() {
	// TODO Auto-generated constructor stub

}

Canteen::~Canteen() {
	// TODO Auto-generated destructor stub
}

bool Canteen::init() {
	Building::init();
	return true;
}

void Canteen::onClick()
{
	Building::showInfoMenu();
}
void Canteen::infoMenuInit()
{
	CCLog("ok");
	buildingView->loadTexture("canteen.png");
	sub_btn->setTouchEnabled(true);
	sub_btn->addTouchEventListener(this,toucheventselector(Canteen::goBackToCastle));
	add_btn->setTouchEnabled(true);
	add_btn->addTouchEventListener(this,toucheventselector(Canteen::goToWork));

	Building::setInfoMenu("这是饭堂","100","50","4","2");

}
void Canteen::refreshView()
{
	this->initWithFile("canteen.png");
}
void Canteen::goToWork(CCObject *pSender, TouchEventType type)
{
	if(type == TOUCH_EVENT_ENDED){
		CCPoint tmpPoint = res->getCastleMap();
		CookMan* cookMan = CookMan::create();
		cookMan->setPosition(tmpPoint.x * 45,tmpPoint.y * 45);
		res->getBuildingLayer()->addChild(cookMan,4);
		res->setPosValue(buildingMap.x, buildingMap.y, 0);
		cookMan->BFS((int)tmpPoint.x,(int)tmpPoint.y,(int)buildingMap.x,(int)buildingMap.y,buildingIndex,"goToWork");
		res->setPosValue(buildingMap.x, buildingMap.y, 1);
	}
}
void Canteen::goBackToCastle(CCObject *pSender, TouchEventType type)
{
	if(type == TOUCH_EVENT_ENDED){
		CCPoint tmpPoint = res->getCastleMap();
		CookMan* cookMan = CookMan::create();
		cookMan->setPosition(buildingMap.x * 45,buildingMap.y * 45);
		res->getBuildingLayer()->addChild(cookMan,4);
		cookMan->BFS((int)buildingMap.x,(int)buildingMap.y,(int)tmpPoint.x,(int)tmpPoint.y,0,"goBackToCastle");
	}
}
