/*
 * PeopleMoveObject.h
 *
 *  Created on: Mar 20, 2014
 *      Author: noonnightstorm
 */

#ifndef PEOPLEMOVEOBJECT_H_
#define PEOPLEMOVEOBJECT_H_

#include "cocos2d.h"

using namespace cocos2d;

class PeopleMoveObject: public cocos2d::CCObject {
public:
	PeopleMoveObject();
	virtual ~PeopleMoveObject();
	void setPath(int fIndex,int fx,int fy,int tIndex,int tx,int ty,int peopleType);
private:
	int _fx;
	int _fy;
	int _tx;
	int _ty;
	int _fIndex;
	int _tIndex;
	int _peopleType;
};

#endif /* PEOPLEMOVEOBJECT_H_ */
