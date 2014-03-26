/*
 * DormitoryWrk.h
 *
 *  Created on: Mar 19, 2014
 *      Author: noonnightstorm
 */

#ifndef DORMITORYWRK_H_
#define DORMITORYWRK_H_

#include "Building.h"
#include "cocos2d.h"

using namespace cocos2d;

class DormitoryWrk: public Building {
public:
	DormitoryWrk();
	virtual ~DormitoryWrk();

	void onClick();

	void infoMenuInit();
	void refreshView();

	bool init();

	CREATE_FUNC(DormitoryWrk);
};

#endif /* DORMITORYWRK_H_ */
