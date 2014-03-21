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
	this->initWithFile("building.png");
	return true;
}

void Building::setMapIndex(int x,int y){
	buildingMap.x = x;
	buildingMap.y = y;
}

void Building::setBuildingIndex(int index){
	buildingIndex = index;
}

void Building::building(int MapX,int MapY,string type){
	GameResources* res = GameResources::GetInstance();
	CCPoint* point = new CCPoint();
	point->setPoint(MapX*45,MapY*45);
	this->setPosition(*point);
	buildingMap.x = MapX;
	buildingMap.y = MapY;
	buildingType = type;
	buildingIndex = res->getBuildingIndex();
	res->addBuildingIndex();

	if(type.compare("Castle") == 0){
		this->initWithFile("canteen.png");
	}
	else if(type.compare("Canteen") == 0){
		this->initWithFile("canteen.png");
	}
	else if(type.compare("ClassRoom") == 0){
		this->initWithFile("teachBuilding.png");
	}
	else if(type.compare("DormitoryStu") == 0){
		this->initWithFile("dormitory_stu.png");
	}
	else if(type.compare("DormitoryWrk") == 0){
		this->initWithFile("dormitory_worker.png");
	}
}

void Building::doBuilding(int MapX,int MapY,string type){
	GameResources* res = GameResources::GetInstance();
	CCPoint* point = new CCPoint();
	point->setPoint(MapX*45,MapY*45);
	this->setPosition(*point);
	buildingMap.x = MapX;
	buildingMap.y = MapY;
	buildingType = type;
	buildingIndex = res->getBuildingIndex();
	res->addBuildingIndex();
	moveToBuilding();
}

void Building::moveToBuilding(){
	GameResources* res = GameResources::GetInstance();
	CCPoint tmpPoint = res->getCastleMap();

	Worker* worker = Worker::create();
	worker->setPosition(tmpPoint.x * 45,tmpPoint.y * 45);
	res->getBuildingLayer()->addChild(worker,4);
	worker->BFS((int)tmpPoint.x,(int)tmpPoint.y,(int)buildingMap.x,(int)buildingMap.y);
}

void Building::beginToBuilding(){

}

void Building::finishBuilding(){

}

/*void Building::doBuilding(){
	GameResources* res = GameResources::GetInstance();
	CCPoint tmpPoint = res->getCastleMap();

	Worker* worker = Worker::create();
	worker->setPosition(tmpPoint.x * 45,tmpPoint.y * 45);
	res->getBuildingLayer()->addChild(worker,4);
	worker->BFS((int)tmpPoint.x,(int)tmpPoint.y,(int)buildingMap.x,(int)buildingMap.y);
}*/

