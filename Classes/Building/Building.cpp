/*
 * Building.cpp
 *
 *  Created on: Mar 18, 2014
 *      Author: C860
 */

#include "Building.h"
#include "GameResources.h"
#include "cocos-ext.h"

using namespace cocos2d;
using namespace cocos2d::extension;
using namespace cocos2d::gui;

Building::Building() {
	// TODO Auto-generated constructor stub

}

Building::~Building() {
	// TODO Auto-generated destructor stub
}

bool Building::init() {
	if (!CCSprite::init() )
	{
		return false;
	}

	return true;
}

void Building::setMapIndex(float x,float y){
	buildingMap.x = x;
	buildingMap.y = y;
}

void Building::setBuildingIndex(int index){
	buildingIndex = index;
}
