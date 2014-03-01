/*
 * AddBuildingLayer.h
 *
 *  Created on: Feb 26, 2014
 *      Author: C860
 */

#ifndef ADDBUILDINGLAYER_H_
#define ADDBUILDINGLAYER_H_

#include "cocos2d.h"
#include "TouchListener.h"

using namespace cocos2d;

class AddBuildingLayer: public TouchListener {
public:
	AddBuildingLayer();
	virtual ~AddBuildingLayer();
	bool init();
	virtual void registerWithTouchDispatcher();
	virtual bool ccTouchBegan(CCTouch* touch, CCEvent* event);//按下
	virtual void ccTouchMoved(CCTouch* touch, CCEvent* event);//移动
	virtual void ccTouchEnded(CCTouch* touch, CCEvent* event);//松开
	virtual void test(CCObject *pSender);
	CREATE_FUNC(AddBuildingLayer);
};

#endif /* ADDBUILDINGLAYER_H_ */
