/*
 * ClassRoom.cpp
 *
 *  Created on: Mar 19, 2014
 *      Author: noonnightstorm
 */

#include "ClassRoom.h"

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
}
void ClassRoom::refreshView()
{
	this->initWithFile("teachBuilding.png");
}
