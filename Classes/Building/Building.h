/*
 * Building.h
 *
 *  Created on: Mar 18, 2014
 *      Author: C860
 */

#ifndef BUILDING_H_
#define BUILDING_H_

#include "cocos2d.h"
#include "cocos-ext.h"
#include <iostream>
#include <string>

using namespace std;
using namespace cocos2d;
using namespace cocos2d::extension;
using namespace cocos2d::gui;

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

protected:
	CCPoint buildingMap;
	int buildingIndex;
	string buildingType;
	CCArmature* _armature;

private:
	void moveToBuilding();
	void beginToBuilding(CCObject* obj);
	void finishBuilding();
	void moveBack();
};

#endif /* BUILDING_H_ */
