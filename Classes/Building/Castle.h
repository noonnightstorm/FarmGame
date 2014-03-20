/*
 * Castle.h
 *
 *  Created on: Mar 20, 2014
 *      Author: noonnightstorm
 */

#ifndef CASTLE_H_
#define CASTLE_H_

#include "Building.h"
#include "cocos2d.h"

using namespace cocos2d;

class Castle: public Building {
public:
	Castle();
	virtual ~Castle();
	bool init();

	CREATE_FUNC(Castle);
};

#endif /* CASTLE_H_ */
