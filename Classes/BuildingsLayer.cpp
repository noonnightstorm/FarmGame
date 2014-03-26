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
#include "Building/ClassRoom.h"

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

	Castle* castle = Castle::create();
	castle->building(3,4);
	this->addChild(castle,5);

	/*Canteen* canteen = Canteen::create();
	canteen->doBuilding(8,1);
	this->addChild(canteen,5);

	ClassRoom* classRoom = ClassRoom::create();
	classRoom->doBuilding(7,4);
	this->addChild(classRoom,5);*/

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
