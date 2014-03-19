/*
 * Canteen.h
 *
 *  Created on: Mar 19, 2014
 *      Author: noonnightstorm
 */

#ifndef CANTEEN_H_
#define CANTEEN_H_

#include "Building.h"
#include "cocos2d.h"

using namespace cocos2d;

class Canteen: public Building {
public:
	Canteen();
	virtual ~Canteen();
	bool init();

	CREATE_FUNC(Canteen);
};

#endif /* CANTEEN_H_ */
