/*
 * Canteen.cpp
 *
 *  Created on: Mar 19, 2014
 *      Author: noonnightstorm
 */

#include "Canteen.h"

Canteen::Canteen() {
	// TODO Auto-generated constructor stub

}

Canteen::~Canteen() {
	// TODO Auto-generated destructor stub
}

bool Canteen::init() {
	if (!CCSprite::init() )
	{
		return false;
	}
	this->initWithFile("canteen.png");
	return true;
}

