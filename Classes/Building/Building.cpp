/*
 * Building.cpp
 *
 *  Created on: Mar 18, 2014
 *      Author: C860
 */

#include "Building.h"
#include "GameResources.h"
#include "cocos-ext.h"
#include "People/Worker.h"

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

void Building::setMapIndex(int x,int y){
	buildingMap.x = x;
	buildingMap.y = y;
}

void Building::setBuildingIndex(int index){
	buildingIndex = index;
}

void Building::doBuilding(){
	GameResources* res = GameResources::GetInstance();
	CCPoint tmpPoint = res->getCastleMap();

	Worker* worker = Worker::create();
	worker->setPosition(tmpPoint.x * 45,tmpPoint.y * 45);
	res->getBuildingLayer()->addChild(worker,4);
	worker->BFS((int)tmpPoint.x,(int)tmpPoint.y,(int)buildingMap.x,(int)buildingMap.y);
}

