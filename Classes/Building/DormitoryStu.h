/*
 * DormitoryStu.h
 *
 *  Created on: Mar 19, 2014
 *      Author: noonnightstorm
 */

#ifndef DORMITORYSTU_H_
#define DORMITORYSTU_H_

#include "Building.h"
#include "cocos2d.h"

using namespace cocos2d;

class DormitoryStu: public Building {
public:
	DormitoryStu();
	virtual ~DormitoryStu();
	bool init();

	CREATE_FUNC(DormitoryStu);
};

#endif /* DORMITORYSTU_H_ */
