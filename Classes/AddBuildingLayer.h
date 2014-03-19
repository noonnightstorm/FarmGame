/*
 * AddBuildingLayer.h
 *
 *  Created on: Mar 19, 2014
 *      Author: C860
 */

#ifndef ADDBUILDINGLAYER_H_
#define ADDBUILDINGLAYER_H_

#include "cocos2d.h"
#include "TouchListener.h"
#include <string>

using namespace cocos2d;
using namespace std;

class AddBuildingLayer: public TouchListener {
public:
	AddBuildingLayer();
	virtual ~AddBuildingLayer();
	bool init();
	virtual void registerWithTouchDispatcher();
	virtual bool ccTouchBegan(CCTouch* touch, CCEvent* event);//按下
	virtual void ccTouchMoved(CCTouch* touch, CCEvent* event);//移动
	virtual void ccTouchEnded(CCTouch* touch, CCEvent* event);//松开
	void setBuildingStr(string name);
	string getBuildingStr();
	CREATE_FUNC(AddBuildingLayer);

private:
	CCSize winSize;
	CCPoint origin;
	CCPoint beginPoint;
	CCPoint endPoint;
	string buildName;
};

#endif /* ADDBUILDINGLAYER_H_ */
