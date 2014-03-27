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
}
void DormitoryStu::refreshView()
{
	this->initWithFile("dormitory_stu.png");
}
