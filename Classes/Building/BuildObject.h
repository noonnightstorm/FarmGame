/*
 * BuildObject.h
 *
 *  Created on: Mar 19, 2014
 *      Author: noonnightstorm
 */

#ifndef BUILDOBJECT_H_
#define BUILDOBJECT_H_

#include "cocos2d.h"
#include <string>

using namespace cocos2d;
using namespace std;

class BuildObject: public cocos2d::CCObject {
public:
	BuildObject();
	virtual ~BuildObject();
	void setPosition(CCPoint point);
	CCPoint getPosition();
	void setBuildingStr(string name);
	string getBuildingStr();
	void setTag(int tag);
	int getTag();
private:
	string BuildingName;
	CCPoint BuildingPoint;
	int BuildingTag;
};

#endif /* BUILDOBJECT_H_ */
