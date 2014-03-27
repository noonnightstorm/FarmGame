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

	void onClick();

	void infoMenuInit();
	void refreshView();

	void goToWork(CCObject *pSender, TouchEventType type);
	void goBackToCastle(CCObject *pSender, TouchEventType type);

	CREATE_FUNC(ClassRoom);
};

#endif /* CLASSROOM_H_ */
