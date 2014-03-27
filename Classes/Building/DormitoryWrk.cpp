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
	//Building::showInfoMenu();
}
void DormitoryWrk::infoMenuInit()
{
	buildingView->loadTexture("dormitory_worker.png");
	char temp_worker_char[100];
	sprintf(temp_worker_char, "%d", worker);

	Building::setInfoMenu("员工宿舍。","35","0","5",temp_worker_char);
}
void DormitoryWrk::refreshView()
{
	this->initWithFile("dormitory_worker.png");
}
