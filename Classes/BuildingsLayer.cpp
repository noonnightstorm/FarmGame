/*
 * BuildingsLayer.h
 *
 *  Created on: Feb 13, 2014
 *      Author: c860
 */
#include "BuildingsLayer.h"


using namespace cocos2d;


BuildingsLayer::BuildingsLayer() {
	// TODO Auto-generated constructor stub

}

BuildingsLayer::~BuildingsLayer() {
	// TODO Auto-generated destructor stub
}

bool BuildingsLayer::init(){
	//设置为可点击
	if (!CCLayer::init() )
	{
		return false;
	}

	return true;
}
void BuildingsLayer::registerWithTouchDispatcher()
{
}


bool BuildingsLayer::ccTouchBegan(CCTouch* touch, CCEvent* event)
{
	return true;
}

void BuildingsLayer::ccTouchMoved(CCTouch* touch, CCEvent* event)
{
}

void BuildingsLayer::ccTouchEnded(CCTouch* touch, CCEvent* event)
{
}
