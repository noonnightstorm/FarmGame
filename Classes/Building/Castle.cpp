/*
 * Castle.cpp
 *
 *  Created on: Mar 20, 2014
 *      Author: noonnightstorm
 */

#include "Castle.h"

Castle::Castle() {
	// TODO Auto-generated constructor stub

}

Castle::~Castle() {
	// TODO Auto-generated destructor stub
}

bool Castle::init() {
	/*if (!CCSprite::init() )
	{
		return false;
	}
	this->initWithFile("canteen.png");
	return true;*/
	Building::init();
	return true;
}

