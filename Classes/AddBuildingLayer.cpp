/*
 * AddBuildingLayer.h
 *
 *  Created on: Mar 19, 2014
 *      Author: c860
 */
#include "AddBuildingLayer.h"
#include "TouchListener.h"
#include "GameResources.h"
#include "Building/BuildObject.h"

using namespace cocos2d;


AddBuildingLayer::AddBuildingLayer() {
	// TODO Auto-generated constructor stub

}

AddBuildingLayer::~AddBuildingLayer() {
	// TODO Auto-generated destructor stub
}

bool AddBuildingLayer::init(){
	TouchListener::init();
	GameResources* res = GameResources::GetInstance();

	CCSize size;
	size.height = res->getWinHeight();
	size.width = res->getWinWidth();
	this->setContentSize(size);

	winSize = CCDirector::sharedDirector()->getVisibleSize();
	origin = CCDirector::sharedDirector()->getVisibleOrigin();

	ccColor4B color = ccc4(220, 220, 220, 150);
	CCLayerColor* color_layer = CCLayerColor::create(color);
	color_layer->setPosition(ccp(0,0));
	color_layer->setContentSize(size);

	this->addChild(color_layer,6,100);

	return true;
}
void AddBuildingLayer::registerWithTouchDispatcher()
{
	TouchListener::registerWithTouchDispatcher();
}


bool AddBuildingLayer::ccTouchBegan(CCTouch* touch, CCEvent* event)
{
	TouchListener::ccTouchBegan(touch,event);
	return true;
}

void AddBuildingLayer::ccTouchMoved(CCTouch* touch, CCEvent* event)
{
	TouchListener::ccTouchMoved(touch,event);
}

void AddBuildingLayer::ccTouchEnded(CCTouch* touch, CCEvent* event)
{
	TouchListener::ccTouchEnded(touch,event);

	GameResources* res = GameResources::GetInstance();

	CCPoint point = touch->getLocation();
	if((int)point.x%45>22) {
		point.x = res->getRealWidth((int)((point.x/45)+1));
	}
	else {
		point.x = res->getRealWidth((int)(point.x/45));
	}
	if((int)point.y%45>22) {
		point.y = res->getRealHeight((int)((point.y/45)+1));
	}
	else {
		point.y = res->getRealHeight((int)(point.y/45));
	}
//	point.y = res->getRealHeight((int)(point.y/45));
	BuildObject* obj = new BuildObject();
	obj->setPosition(point);
	obj->setBuildingStr(buildName);
	CCNotificationCenter::sharedNotificationCenter()->postNotification("newBuilding",obj);
}

void AddBuildingLayer::setBuildingStr(string name){
	buildName = name;
}

string  AddBuildingLayer::getBuildingStr(){
	return buildName;
}
