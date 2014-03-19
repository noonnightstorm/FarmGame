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
	if (!CCSprite::init() )
	{
		return false;
	}
	this->initWithFile("dormitory_stu.png");
	return true;
}

