/*
 * PeopleMoveObject.h
 *
 *  Created on: Mar 20, 2014
 *      Author: noonnightstorm
 */

#ifndef PEOPLEMOVEOBJECT_H_
#define PEOPLEMOVEOBJECT_H_

#include "cocos2d.h"
#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;
using namespace cocos2d;

class PeopleMoveObject: public cocos2d::CCObject {
public:
	PeopleMoveObject();
	virtual ~PeopleMoveObject();

	void setInfo(string info,int buildingIndex);
	string getWorkInfo();
	int getBuildingIndex();
private:
	string _info;
	int _buildingIndex;
};

#endif /* PEOPLEMOVEOBJECT_H_ */
