/*
 * Building.h
 *
 *  Created on: Mar 18, 2014
 *      Author: C860
 */

#ifndef BUILDING_H_
#define BUILDING_H_

#include "cocos2d.h"
#include <iostream>
#include <string>

using namespace std;
using namespace cocos2d;

class Building : public CCSprite {
public:
	Building();
	virtual ~Building();
	bool init();
	static Building* create(const char *filename);

	void setMapIndex(int x,int y);
	void setBuildingIndex(int index);
	void building(int MapX,int MapY,string type);
	void doBuilding(int MapX,int MapY,string type);
	CREATE_FUNC(Building);
private:
	CCPoint buildingMap;
	int buildingIndex;
	string buildingType;
	//static CCArmature* _armature;
	void moveToBuilding();
	void beginToBuilding();
	void finishBuilding();
};

#endif /* BUILDING_H_ */
