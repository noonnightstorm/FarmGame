/*
 * Building.h
 *
 *  Created on: Mar 18, 2014
 *      Author: C860
 */

#ifndef BUILDING_H_
#define BUILDING_H_

#include "cocos2d.h"

using namespace cocos2d;

class Building : public CCSprite {
public:
	Building();
	virtual ~Building();
	bool init();
	static Building* create(const char *filename);

	void setMapIndex(int x,int y);
	void setBuildingIndex(int index);

	void doBuilding();

private:
	CCPoint buildingMap;
	int buildingIndex;
};

#endif /* BUILDING_H_ */
