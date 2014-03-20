/*
 * BuildingsLayer.h
 *
 *  Created on: Feb 13, 2014
 *      Author: c860
 */
#include "BuildingsLayer.h"
#include "TouchListener.h"
#include "GameResources.h"
#include "Building/Building.h"
#include "Building/Canteen.h"
#include "Building/Castle.h"

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
	res->setBuildingLayer(this);

	winSize = CCDirector::sharedDirector()->getVisibleSize();
	origin = CCDirector::sharedDirector()->getVisibleOrigin();

	CCPoint* point1 = new CCPoint();
	point1->setPoint(135,180);
	Castle* castle = Castle::create();
	castle->setPosition(*point1);
	castle->setBuildingIndex(0);
	castle->setMapIndex((int)(135/45),(int)(180/45));
	this->addChild(castle,5);
	res->addBuildingIndex();

	CCPoint* point2 = new CCPoint();
	point2->setPoint(360,45);
	Canteen* canteen = Canteen::create();
	canteen->setPosition(*point2);
	canteen->setBuildingIndex(1);
	canteen->setMapIndex((int)(360/45),(int)(45/45));
	this->addChild(canteen,5);
	res->addBuildingIndex();
	canteen->doBuilding();

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
