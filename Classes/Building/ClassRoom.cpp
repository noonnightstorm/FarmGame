/*
 * ClassRoom.cpp
 *
 *  Created on: Mar 19, 2014
 *      Author: noonnightstorm
 */

#include "ClassRoom.h"
#include "People/Girl.h"

ClassRoom::ClassRoom() {
	// TODO Auto-generated constructor stub

}

ClassRoom::~ClassRoom() {
	// TODO Auto-generated destructor stub
}

bool ClassRoom::init() {
	/*if (!CCSprite::init() )
	{
		return false;
	}
	this->initWithFile("teachBuilding.png");
	return true;*/
	Building::init();
	return true;
}
void ClassRoom::onClick()
{
	Building::showInfoMenu();
}
void ClassRoom::infoMenuInit()
{
	buildingView->loadTexture("teachBuilding.png");
	sub_btn->setTouchEnabled(true);
	sub_btn->addTouchEventListener(this,toucheventselector(ClassRoom::goBackToCastle));
	add_btn->setTouchEnabled(true);
	add_btn->addTouchEventListener(this,toucheventselector(ClassRoom::goToWork));
}
void ClassRoom::refreshView()
{
	this->initWithFile("teachBuilding.png");
}

void ClassRoom::goToWork(CCObject *pSender, TouchEventType type)
{
	if(type == TOUCH_EVENT_ENDED){
		CCPoint tmpPoint = res->getCastleMap();
		Girl* girl = Girl::create();
		girl->setPosition(tmpPoint.x * 45,tmpPoint.y * 45);
		res->getBuildingLayer()->addChild(girl,4);
		res->setPosValue(buildingMap.x, buildingMap.y, 0);
		girl->BFS((int)tmpPoint.x,(int)tmpPoint.y,(int)buildingMap.x,(int)buildingMap.y,buildingIndex,"goToWork");
		res->setPosValue(buildingMap.x, buildingMap.y, 1);
	}
}
void ClassRoom::goBackToCastle(CCObject *pSender, TouchEventType type)
{
	if(type == TOUCH_EVENT_ENDED){
		CCPoint tmpPoint = res->getCastleMap();
		Girl* girl = Girl::create();
		girl->setPosition(buildingMap.x * 45,buildingMap.y * 45);
		res->getBuildingLayer()->addChild(girl,4);
		girl->BFS((int)buildingMap.x,(int)buildingMap.y,(int)tmpPoint.x,(int)tmpPoint.y,0,"goBackToCastle");
	}
}
