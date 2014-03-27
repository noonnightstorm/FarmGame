/*
 * DormitoryStu.cpp
 *
 *  Created on: Mar 19, 2014
 *      Author: noonnightstorm
 */

#include "DormitoryStu.h"

DormitoryStu::DormitoryStu() {
	// TODO Auto-generated constructor stub

}

DormitoryStu::~DormitoryStu() {
	// TODO Auto-generated destructor stub
}

bool DormitoryStu::init() {
	/*if (!CCSprite::init() )
	{
		return false;
	}
	this->initWithFile("dormitory_stu.png");
	return true;*/
	Building::init();
	return true;
}
void DormitoryStu::onClick()
{
	//Building::showInfoMenu();
}
void DormitoryStu::infoMenuInit()
{
	buildingView->loadTexture("dormitory_stu.png");
	char temp_worker_char[100];
	sprintf(temp_worker_char, "%d", worker);

	Building::setInfoMenu("学生宿舍。","30","0","5",temp_worker_char);
}
void DormitoryStu::refreshView()
{
	this->initWithFile("dormitory_stu.png");
}
