/*
 * ClassRoom.h
 *
 *  Created on: Mar 19, 2014
 *      Author: noonnightstorm
 */

#ifndef CLASSROOM_H_
#define CLASSROOM_H_

#include "Building.h"
#include "cocos2d.h"

using namespace cocos2d;

class ClassRoom: public Building {
public:
	ClassRoom();
	virtual ~ClassRoom();
	bool init();

	CREATE_FUNC(ClassRoom);
};

#endif /* CLASSROOM_H_ */
