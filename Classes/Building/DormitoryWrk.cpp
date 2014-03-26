/*
 * DormitoryWrk.cpp
 *
 *  Created on: Mar 19, 2014
 *      Author: noonnightstorm
 */

#include "DormitoryWrk.h"

DormitoryWrk::DormitoryWrk() {
	// TODO Auto-generated constructor stub

}

DormitoryWrk::~DormitoryWrk() {
	// TODO Auto-generated destructor stub
}

bool DormitoryWrk::init() {
	/*if (!CCSprite::init() )
	{
		return false;
	}
	this->initWithFile("dormitory_worker.png");
	return true;*/
	Building::init();
	return true;
}
void DormitoryWrk::onClick()
{
	Building::showInfoMenu();
}
void DormitoryWrk::infoMenuInit()
{
	buildingView->loadTexture("dormitory_worker.png");
}
void DormitoryWrk::refreshView()
{
	this->initWithFile("dormitory_worker.png");
}
